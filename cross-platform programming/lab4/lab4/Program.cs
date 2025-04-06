using System;

public class Product
{
    public string Name { get; set; } 
    public decimal Price { get; set; }
    
    public Product() { Name = "Невідомий товар"; Price = 0; }
    public Product(string name, decimal price) { this.Name = name; this.Price = price; }
    public override string ToString() { return $"Назва: {Name}, Ціна: {Price}"; }
}

public class Accessory : Product
{
    public string Type { get; set; }

    public Accessory() : base()
    {
        Type = "Аксесуар";
    }

    public Accessory(string name, decimal price, string type) : base(name, price)
    {
        this.Type = type;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип: {Type}";
    }
}

public class Watch : Product
{
    public string Mechanism { get; set; }
    public string Brand { get; set; }
    
    public Watch() : base() {Mechanism = "Кварцовий"; Brand = "Невідомий бренд";}

    public Watch(string name, decimal price, string mechanism, string brand)
        : base(name, price)
    {
        this.Mechanism = mechanism;
        this.Brand = brand;
    }
    public override string ToString() { return $"{base.ToString()}, Механізм: {Mechanism}, Бренд: {Brand}"; }
}

public class SmartWatch : Watch
{
    public bool HasGps { get; set; }
    public bool HasHeartRateMonitor { get; set; }
    
    public SmartWatch() : base() { HasGps = false; HasHeartRateMonitor = false; }
    public SmartWatch(string name, decimal price, string mechanism, string brand, bool hasGps, bool hasHeartRateMonitor)
        : base(name, price, mechanism, brand)
    {
        this.HasGps = hasGps;
        this.HasHeartRateMonitor = hasHeartRateMonitor;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, GPS: {ToYesNo(HasGps)}, Монітор серця: {ToYesNo(HasHeartRateMonitor)}";
    }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

public class LuxuryWatch : Watch
{
    public string Material { get; set; }
    public bool LimitedEdition { get; set; }
    
    public LuxuryWatch() : base()
    {
        Material = "Золото"; 
        LimitedEdition = false; 
    }
    public LuxuryWatch(string name, decimal price, string mechanism, string brand, string material, bool limitedEdition)
        : base(name, price, mechanism, brand)
    {
        this.Material = material;
        this.LimitedEdition = limitedEdition;
    }
    public override string ToString() { return $"{base.ToString()}, Матеріал: {Material}, Обмежений випуск: {ToYesNo(LimitedEdition)}"; }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

public class SportWatch : Watch
{
    public int WaterResistance { get; set; }
    public bool SmartFeatures { get; set; }

    public SportWatch() : base() { WaterResistance = 50; SmartFeatures = false; }

    public SportWatch(string name, decimal price, string mechanism, string brand, int waterResistance, bool smartFeatures)
        : base(name, price, mechanism, brand)
    {
        this.WaterResistance = waterResistance;
        this.SmartFeatures = smartFeatures;
    }
    public override string ToString() { return $"{base.ToString()}, Водозахист: {WaterResistance} м, Розумні функції: {ToYesNo(SmartFeatures)}"; }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

public class LeatherAccessory : Accessory
{
    public string StrapMaterial { get; set; }
    public bool HasBuckle { get; set; }        

    public LeatherAccessory() : base()
    {
        StrapMaterial = "Шкіра";
        HasBuckle = true;
    }

    public LeatherAccessory(string name, decimal price, string type, string strapMaterial, bool hasBuckle)
        : base(name, price, type)
    {
        this.StrapMaterial = strapMaterial;
        this.HasBuckle = hasBuckle;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Матеріал ремінця: {StrapMaterial}, Має пряжку: {ToYesNo(HasBuckle)}";
    }

    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

public class MetalAccessory : Accessory
{
    public string MetalType { get; set; }  
    public bool IsPolished { get; set; }   

    public MetalAccessory() : base()
    {
        MetalType = "Нержавіюча сталь";
        IsPolished = true;
    }

    public MetalAccessory(string name, decimal price, string type, string metalType, bool isPolished)
        : base(name, price, type)
    {
        this.MetalType = metalType;
        this.IsPolished = isPolished;
    }

    public override string ToString()
    {
        return $"{base.ToString()}, Тип металу: {MetalType}, Полірований: {ToYesNo(IsPolished)}";
    }

    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

public class Container
{
    private class Node
    {
        public Product Data { get; set; }
        public Node Previous { get; set; }
        public Node Next { get; set; }

        public Node(Product data)
        {
            Data = data;
            Previous = null;
            Next = null;
        }
    }

    private Node head;
    private Node tail;
    private int count;
    
    public Container()
    {
        head = null;
        tail = null;
        count = 0;
    }
    
    public void Add(Product product)
    {
        Node newNode = new Node(product);
        
        if (head == null)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail.Next = newNode;
            newNode.Previous = tail;
            tail = newNode;
        }
        count++;
    }
    
    public void SortByName(bool ascending = true)
    {
        if (count <= 1) return;
        
        bool swapped;
        do
        {
            swapped = false;
            Node current = head;
            
            while (current != null && current.Next != null)
            {
                int comparison = string.Compare(current.Data.Name, current.Next.Data.Name, StringComparison.OrdinalIgnoreCase);
                bool shouldSwap = ascending ? comparison > 0 : comparison < 0;
                
                if (shouldSwap)
                {
                    SwapNodes(current, current.Next);
                    swapped = true;
                }
                else
                {
                    current = current.Next;
                }
            }
        } while (swapped);
    }
    
    public void RemoveAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
        
        Node current = GetNodeAt(index);
        
        if (current.Previous != null)
            current.Previous.Next = current.Next;
        else
            head = current.Next;
            
        if (current.Next != null)
            current.Next.Previous = current.Previous;
        else
            tail = current.Previous;
            
        count--;
    }
    
    public void SortByPrice(bool ascending = true)
    {
        if (count <= 1) return;
        
        bool swapped;
        do
        {
            swapped = false;
            Node current = head;
            
            while (current != null && current.Next != null)
            {
                bool shouldSwap = ascending 
                    ? current.Data.Price > current.Next.Data.Price 
                    : current.Data.Price < current.Next.Data.Price;
                
                if (shouldSwap)
                {
                    SwapNodes(current, current.Next);
                    swapped = true;
                }
                else
                {
                    current = current.Next;
                }
            }
        } while (swapped);
    }
    
    public Product GetAt(int index)
    {
        return GetNodeAt(index).Data;
    }
    
    public int Count => count;
    
    private Node GetNodeAt(int index)
    {
        if (index < 0 || index >= count)
            throw new IndexOutOfRangeException();
            
        Node current;
        if (index < count / 2)
        {
            current = head;
            for (int i = 0; i < index; i++)
                current = current.Next;
        }
        else
        {
            current = tail;
            for (int i = count - 1; i > index; i--)
                current = current.Previous;
        }
        return current;
    }
    
    private void SwapNodes(Node a, Node b)
    {
        Product temp = a.Data;
        a.Data = b.Data;
        b.Data = temp;
    }
    
    public override string ToString()
    {
        string result = "";
        Node current = head;
        while (current != null)
        {
            result += current.Data.ToString() + "\n";
            current = current.Next;
        }
        return result;
    }
}

class Program
{
    const string BLACK = "\u001b[30m";
    const string YELLOW = "\u001b[33m";
    const string MAGENTA = "\u001b[35m";
    const string WHITE = "\u001b[37m";
    const string BRIGHT_BLACK = "\u001b[90m";
    const string BRIGHT_RED = "\u001b[91m";
    const string BRIGHT_GREEN = "\u001b[92m";
    const string BRIGHT_YELLOW = "\u001b[93m";
    const string BRIGHT_BLUE = "\u001b[94m";
    const string BRIGHT_MAGENTA = "\u001b[95m";
    const string BRIGHT_CYAN = "\u001b[96m";     
    const string BRIGHT_WHITE = "\u001b[97m";
    const string RESET = "\u001b[0m";
    const string RED = "\u001b[31m";
    const string TABUL = "\t\t\t\t\t\t\t";
    
    static void DisplayProductsTable(Container products)
    {
        if (products.Count == 0)
        {
            Console.WriteLine($"{RED}\nНемає доданих товарів.{RESET}");
            return;
        }
        
        const int col1Width = 6;
        const int col2Width = 20;
        const int col3Width = 10;
        const int col4Width = 20;
        const int col5Width = 15;
        const int col6Width = 15;
        const int col7Width = 15;
        const int col8Width = 15;
        const int col9Width = 15;
        
        string separator = new string('-', 
            col1Width + col2Width + col3Width + col4Width + col5Width + 
            col6Width + col7Width + col8Width + col9Width + 28);

        Console.WriteLine("\n" + separator);
        Console.WriteLine(
            $"| {$"{BRIGHT_YELLOW}№ п/п".PadRight(col1Width)} " +
            $"| {"Назва".PadRight(col2Width)} " +
            $"| {"Ціна".PadRight(col3Width)} " +
            $"| {"Тип".PadRight(col4Width)} " +
            $"| {"Механізм".PadRight(col5Width)} " +
            $"| {"Бренд".PadRight(col6Width)} " +
            $"| {"Матеріал".PadRight(col7Width)} " +
            $"| {"Водозахист".PadRight(col8Width)} " +
            $"| {"Функції".PadRight(col9Width)} |{RESET}");
        Console.WriteLine(separator);

        for (int i = 0; i < products.Count; i++)
        {
            Product product = products.GetAt(i);
            string num = (i + 1).ToString();
            string name = product.Name.Length > col2Width ? product.Name.Substring(0, col2Width-3) + "..." : product.Name;
            string price = product.Price.ToString();
            string type = "-";
            string mechanism = "-";
            string brand = "-";
            string material = "-";
            string waterResistance = "-";
            string features = "-";
            
            if (product is Watch watch)
            {
                mechanism = watch.Mechanism;
                brand = watch.Brand;
                type = "Годинник";
                
                if (watch is LuxuryWatch lw)
                {
                    type = "Люксовий";
                    material = lw.Material;
                    features = lw.LimitedEdition ? "Обмежений" : "-";
                }
                else if (watch is SportWatch sw)
                {
                    type = "Спортивний";
                    waterResistance = sw.WaterResistance.ToString() + " м";
                    features = sw.SmartFeatures ? "Так" : "-";
                }
                else if (watch is SmartWatch smw)
                {
                    type = "Смарт";
                    features = (smw.HasGps ? "GPS+" : "") + (smw.HasHeartRateMonitor ? " HR+" : "");
                    if (features == "") features = "-";
                }
            }
            else if (product is Accessory accessory)
            {
                type = accessory.Type;
                
                if (accessory is LeatherAccessory la)
                {
                    material = la.StrapMaterial;
                    features = la.HasBuckle ? "Пряжка" : "-";
                }
                else if (accessory is MetalAccessory ma)
                {
                    material = ma.MetalType;
                    features = ma.IsPolished ? "Полірований" : "-";
                }
            }
            
            mechanism = mechanism.Length > col5Width ? mechanism.Substring(0, col5Width-3) + "..." : mechanism;
            brand = brand.Length > col6Width ? brand.Substring(0, col6Width-3) + "..." : brand;
            material = material.Length > col7Width ? material.Substring(0, col7Width-3) + "..." : material;
            features = features.Length > col9Width ? features.Substring(0, col9Width-3) + "..." : features;
            
            Console.WriteLine(
                $"| {num.PadRight(col1Width)} " +
                $"| {name.PadRight(col2Width)} " +
                $"| {price.PadRight(col3Width)} " +
                $"| {type.PadRight(col4Width)} " +
                $"| {mechanism.PadRight(col5Width)} " +
                $"| {brand.PadRight(col6Width)} " +
                $"| {material.PadRight(col7Width)} " +
                $"| {waterResistance.PadRight(col8Width)} " +
                $"| {features.PadRight(col9Width)} |");
            Console.WriteLine(separator);
        }
    }
    
    static Product CreateAccessoryManually()
    {
        Console.WriteLine("Введіть назву аксесуара:");
        string name = Console.ReadLine();

        Console.WriteLine("Введіть ціну:");
        decimal price = decimal.Parse(Console.ReadLine());
        
        Console.WriteLine("Виберіть тип аксесуара (1: Шкіряний, 2: Металевий):");
        string accessoryChoice = Console.ReadLine();
        
        if (accessoryChoice == "1")
        {
            Console.WriteLine("Введіть тип аксесуара (наприклад, Ремінець, Браслет):");
            string type = Console.ReadLine();

            Console.WriteLine("Введіть матеріал ремінця (Шкіра, Екошкіра тощо):");
            string strapMaterial = Console.ReadLine();

            Console.WriteLine("Має пряжку? (так/ні):");
            bool hasBuckle = Console.ReadLine().ToLower() == "так";

            return new LeatherAccessory(name, price, type, strapMaterial, hasBuckle);
        }
        else
        {
            Console.WriteLine("Введіть тип аксесуара (наприклад, Браслет, Ланцюжок):");
            string type = Console.ReadLine();

            Console.WriteLine("Введіть тип металу (Нержавіюча сталь, Срібло тощо):");
            string metalType = Console.ReadLine();

            Console.WriteLine("Полірований? (так/ні):");
            bool isPolished = Console.ReadLine().ToLower() == "так";

            return new MetalAccessory(name, price, type, metalType, isPolished);
        }
    }
    
    static Product CreateWatchManually()
    {
        Console.WriteLine("Введіть назву годинника:");
        string name = Console.ReadLine();

        Console.WriteLine("Введіть ціну:");
        decimal price = decimal.Parse(Console.ReadLine());

        Console.WriteLine("Введіть механізм (Механічний, Кварцовий, Автоматичний):");
        string mechanism = Console.ReadLine();

        Console.WriteLine("Введіть бренд:");
        string brand = Console.ReadLine();

        Console.WriteLine("Виберіть тип годинників (1: Люксові, 2: Спортивні, 3: Смарт-годинники):");
        string type = Console.ReadLine();

        if (type == "1")
        {
            Console.WriteLine("Введіть матеріал (Золото, Платина, Титан):");
            string material = Console.ReadLine();

            Console.WriteLine("Обмежений випуск? (так/ні):");
            bool limitedEdition = Console.ReadLine().ToLower() == "так";

            return new LuxuryWatch(name, price, mechanism, brand, material, limitedEdition);
        }
        else if (type == "2")
        {
            Console.WriteLine("Введіть водозахист у метрах:");
            int waterRes = int.Parse(Console.ReadLine());

            Console.WriteLine("Чи має розумні функції? (так/ні):");
            bool smartFeaturesChoice = Console.ReadLine().ToLower() == "так";

            return new SportWatch(name, price, mechanism, brand, waterRes, smartFeaturesChoice);
        }
        else if (type == "3")
        {
            Console.WriteLine("Чи має GPS? (так/ні):");
            bool hasGps = Console.ReadLine().ToLower() == "так";

            Console.WriteLine("Чи має монітор серця? (так/ні):");
            bool hasHeartRateMonitor = Console.ReadLine().ToLower() == "так";

            return new SmartWatch(name, price, mechanism, brand, hasGps, hasHeartRateMonitor);
        }
        
        return null;
    }
    
    static Product CreateRandomAccessory(Random rand)
    {
        string[] accessoryNames = { "Браслет Classic", "Ремінець Premium", "Ланцюжок Gold", "Ремінець Sport", "Браслет Silver" };
        decimal[] prices = { 49.99m, 99.99m, 149.99m, 29.99m, 79.99m };
        string[] leatherTypes = { "Шкіряний ремінець", "Шкіряний браслет" };
        string[] metalTypes = { "Металевий браслет", "Металевий ланцюжок" };
        string[] strapMaterials = { "Шкіра", "Екошкіра", "Натуральна шкіра", "Замша" };
        string[] metalMaterials = { "Нержавіюча сталь", "Срібло", "Титан", "Золото" };
        bool[] boolValues = { true, false };
        
        string randName = accessoryNames[rand.Next(accessoryNames.Length)];
        decimal randPrice = prices[rand.Next(prices.Length)];
        bool isLeather = rand.Next(2) == 0;
        
        if (isLeather)
        {
            string randType = leatherTypes[rand.Next(leatherTypes.Length)];
            string randMaterial = strapMaterials[rand.Next(strapMaterials.Length)];
            bool randHasBuckle = boolValues[rand.Next(boolValues.Length)];
            
            return new LeatherAccessory(randName, randPrice, randType, randMaterial, randHasBuckle);
        }
        else
        {
            string randType = metalTypes[rand.Next(metalTypes.Length)];
            string randMetal = metalMaterials[rand.Next(metalMaterials.Length)];
            bool randIsPolished = boolValues[rand.Next(boolValues.Length)];
            
            return new MetalAccessory(randName, randPrice, randType, randMetal, randIsPolished);
        }
    }
    
    static Product CreateRandomWatch(Random rand)
    {
        string[] names = { "Rolex Submariner", "Omega Seamaster", "Apple Watch Series 7", "Casio G-Shock", "Tag Heuer Monaco" };
        decimal[] prices = { 5000m, 3000m, 400.99m, 99.99m, 1500m };
        string[] mechanisms = { "Механічний", "Кварцовий", "Автоматичний" };
        string[] brands = { "Rolex", "Omega", "Apple", "Casio", "Tag Heuer" };
        string[] materials = { "Золото", "Платина", "Титан" };
        bool[] boolValues = { true, false };
        int[] waterResistance = { 50, 100, 200, 500, 1000 };
        
        string randName = names[rand.Next(names.Length)];
        decimal randPrice = prices[rand.Next(prices.Length)];
        string randMechanism = mechanisms[rand.Next(mechanisms.Length)];
        string randBrand = brands[rand.Next(brands.Length)];
        
        int watchType = rand.Next(1, 4);
        
        if (watchType == 1)
        {
            string randMaterial = materials[rand.Next(materials.Length)];
            bool randLimitedEdition = boolValues[rand.Next(boolValues.Length)];
            
            return new LuxuryWatch(randName, randPrice, randMechanism, randBrand, randMaterial, randLimitedEdition);
        }
        else if (watchType == 2)
        {
            int randWaterRes = waterResistance[rand.Next(waterResistance.Length)];
            bool randSmartFeatures = boolValues[rand.Next(boolValues.Length)];
            
            return new SportWatch(randName, randPrice, randMechanism, randBrand, randWaterRes, randSmartFeatures);
        }
        else
        {
            bool randHasGps = boolValues[rand.Next(boolValues.Length)];
            bool randHasHeartRateMonitor = boolValues[rand.Next(boolValues.Length)];
            
            return new SmartWatch(randName, randPrice, randMechanism, randBrand, randHasGps, randHasHeartRateMonitor);
        }
    }
    
    private static string GetSortOrderText(bool ascending)
    {
        return ascending ? "за зростанням" : "за спаданням";
    }
    
    static void Main()
    {
        Random rand = new Random();
        Container products = new Container();
        bool exit = false;

        while (!exit)
        {
            Console.Clear();
            Console.WriteLine($"{TABUL}{BRIGHT_BLUE}Меню:{RESET}");
            Console.WriteLine("1. Ввести дані вручну");
            Console.WriteLine("2. Згенерувати рандомно");
            Console.WriteLine("3. Переглянути всі товари");
            Console.WriteLine("4. Видалити товар");
            Console.WriteLine("5. Сортування");
            Console.WriteLine($"{RED}6. Вихід{RESET}");

            Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
            string choice = Console.ReadLine();
            Product product = null;

            switch (choice)
            {
                case "1":
                    Console.WriteLine("Виберіть тип товару (1: Годинник, 2: Аксесуар):");
                    string productType = Console.ReadLine();
                    
                    if (productType == "1")
                    {
                        product = CreateWatchManually();
                    }
                    else if (productType == "2")
                    {
                        product = CreateAccessoryManually();
                    }
                    else
                    {
                        Console.WriteLine("Невірний вибір типу товару.");
                        break;
                    }

                    if (product != null)
                    {
                        products.Add(product);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товар успішно додано!{RESET}");
                        Console.WriteLine($"\n{BRIGHT_YELLOW}Доданий товар:{RESET}");
                        Console.WriteLine(product.ToString());
                    }
                    break;

                case "2":
                    Console.WriteLine("Виберіть тип товару (1: Годинник, 2: Аксесуар):");
                    string randomProductType = Console.ReadLine();
                    
                    if (randomProductType == "1")
                    {
                        product = CreateRandomWatch(rand);
                    }
                    else if (randomProductType == "2")
                    {
                        product = CreateRandomAccessory(rand);
                    }
                    else
                    {
                        Console.WriteLine("Невірний вибір типу товару.");
                        break;
                    }

                    if (product != null)
                    {
                        products.Add(product);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товар успішно додано!{RESET}");
                        Console.WriteLine($"\n{BRIGHT_YELLOW}Доданий товар:{RESET}");
                        Console.WriteLine(product.ToString());
                    }
                    break;

                case "3":
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Список усіх створених товарів:{RESET}");
                    DisplayProductsTable(products);
                    break;
                    
                case "4":
                    if (products.Count == 0)
                    {
                        Console.WriteLine("\nНемає товарів для видалення.");
                        break;
                    }
                    
                    DisplayProductsTable(products);
                    Console.WriteLine("Введіть номер товару для видалення:");
                    if (int.TryParse(Console.ReadLine(), out int indexToDelete) && indexToDelete > 0 && indexToDelete <= products.Count)
                    {
                        string deletedName = products.GetAt(indexToDelete - 1).Name;
                        products.RemoveAt(indexToDelete - 1);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товар '{deletedName}' успішно видалено!{RESET}");
                    }
                    else
                    {
                        Console.WriteLine($"\n{BRIGHT_RED}Невірний номер товару!{RESET}");
                    }
                    break;

                case "5":
                    if (products.Count == 0)
                    {
                        Console.WriteLine("\nНемає товарів для сортування.");
                        break;
                    }
                
                    Console.WriteLine("Виберіть критерій сортування:");
                    Console.WriteLine("1. За назвою (від А до Я)");
                    Console.WriteLine("2. За ціною");
                    Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
                    string sortFieldChoice = Console.ReadLine();

                    if (sortFieldChoice == "1")
                    {
                        products.SortByName(true); // Always sort by name in ascending order
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товари успішно відсортовані за назвою (від А до Я)!{RESET}");
                        DisplayProductsTable(products);
                    }
                    else if (sortFieldChoice == "2")
                    {
                        Console.WriteLine("Виберіть порядок сортування:");
                        Console.WriteLine("1. За зростанням");
                        Console.WriteLine("2. За спаданням");
                        Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
                        string sortOrderChoice = Console.ReadLine();

                        if (sortOrderChoice != "1" && sortOrderChoice != "2")
                        {
                            Console.WriteLine($"\n{BRIGHT_RED}Невірний вибір порядку сортування!{RESET}");
                            break;
                        }

                        bool ascending = sortOrderChoice == "1";
                        products.SortByPrice(ascending);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товари успішно відсортовані за ціною ({GetSortOrderText(ascending)})!{RESET}");
                        DisplayProductsTable(products);
                    }
                    else
                    {
                        Console.WriteLine($"\n{BRIGHT_RED}Невірний вибір критерію сортування!{RESET}");
                    }
                    break;
                
                case "6":
                    exit = true;
                    Console.WriteLine("Вихід з програми...");
                    break;

                default:
                    Console.WriteLine("Невірний вибір, спробуйте ще раз.");
                    break;
            }

            if (!exit)
            {
                Console.WriteLine("\nНатисніть будь-яку клавішу для повернення до меню...");
                Console.ReadKey();
            }
        }
    }
}