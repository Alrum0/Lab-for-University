using System;
using System.Collections.Generic;

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


//2 рівень
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
        return $"{base.ToString()}, GPS: {ToYesNo(HasGps)}, Монітор сердця: {ToYesNo(HasHeartRateMonitor)}";
    }
    
    private string ToYesNo(bool value) => value ? "Так" : "Ні";
}

//3 рівень
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
/// <summary>
/// 
/// </summary>
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

/// <summary>
/// 
/// </summary>

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

    
    static void DisplayWatchesTable(List<Product> products)
    {
        Console.WriteLine("\n{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}{6,-15}", "Назва", "Ціна", "Механізм", "Бренд", "Матеріал", "Водозахист", "Розумні функції");
        Console.WriteLine(new string('-', 105));

        foreach (var product in products)
        {
            if (product is LuxuryWatch lw)
            {
                Console.WriteLine("{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}{6,-15}",
                    lw.Name,
                    lw.Price,
                    lw.Mechanism,
                    lw.Brand,
                    lw.Material == "" ? "" : lw.Material,
                    "",
                    "");
            }
            else if (product is SportWatch sw)
            {
                Console.WriteLine("{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}{6,-15}",
                    sw.Name,
                    sw.Price,
                    sw.Mechanism,
                    sw.Brand,
                    "",
                    sw.WaterResistance == 0 ? "" : sw.WaterResistance.ToString(),
                    "");
            }
            else if (product is SmartWatch smw)
            {
                Console.WriteLine("{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}{6,-15}",
                    smw.Name,
                    smw.Price,
                    smw.Mechanism,
                    smw.Brand,
                    "",
                    "",
                    smw.HasGps ? "Так" : "");
            }
        }
    }
    
    static void DisplayAccessoriesTable(List<Product> products)
    {
        Console.WriteLine("\n{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}", "Назва", "Ціна", "Тип", "Матеріал", "Пряжка", "Полірований");
        Console.WriteLine(new string('-', 90));

        foreach (var product in products)
        {
            if (product is LeatherAccessory la)
            {
                Console.WriteLine("{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}",
                    la.Name,
                    la.Price,
                    la.Type,
                    la.StrapMaterial,
                    la.HasBuckle ? "Так" : "",
                    "");
            }
            else if (product is MetalAccessory ma)
            {
                Console.WriteLine("{0,-20}{1,-10}{2,-15}{3,-15}{4,-15}{5,-15}",
                    ma.Name,
                    ma.Price,
                    ma.Type,
                    ma.MetalType,
                    "",
                    ma.IsPolished ? "Так" : "");
            }
        }
    }
    
    
    
    static void Main()
    {
        Random rand = new Random();

        string[] names =
            { "Rolex Submariner", "Omega Seamaster", "Apple Watch Series 7", "Casio G-Shock", "Tag Heuer Monaco" };
        decimal[] prices = { 5000m, 3000m, 400.99m, 99.99m, 1500m };
        string[] mechanisms = { "Механічний", "Кварцовий", "Автоматичний" };
        string[] brands = { "Rolex", "Omega", "Apple", "Casio", "Tag Heuer" };
        string[] materials = { "Золото", "Платина", "Титан" };
        bool[] limitedEditions = { true, false };
        int[] waterResistance = { 50, 100, 200, 500, 1000 };
        bool[] smartFeatures = { true, false };

        List<Product> products = new List<Product>();
        bool exit = false;

        while (!exit)
        {
            Console.Clear();
            Console.WriteLine($"{TABUL}{BRIGHT_BLUE}Меню:{RESET}");
            Console.WriteLine("1. Ввести дані вручну");
            Console.WriteLine("2. Згенерувати рандомно");
            Console.WriteLine("3. Переглянути всі товари");
            Console.WriteLine("4. Вихід");
            Console.WriteLine("5. Створити аксесуар (шкіряний/металевий)");

            Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
            string choice = Console.ReadLine();
            Product product = null;

            switch (choice)
            {
                case "1":
                    Console.WriteLine("Введіть назву товару:");
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

                        product = new LuxuryWatch(name, price, mechanism, brand, material, limitedEdition);
                    }
                    else if (type == "2")
                    {
                        Console.WriteLine("Введіть водозахист у метрах:");
                        int waterRes = int.Parse(Console.ReadLine());

                        Console.WriteLine("Чи має розумні функції? (так/ні):");
                        bool smartFeaturesChoice = Console.ReadLine().ToLower() == "так";

                        product = new SportWatch(name, price, mechanism, brand, waterRes, smartFeaturesChoice);
                    }
                    else if (type == "3")
                    {
                        Console.WriteLine("Чи має GPS? (так/ні):");
                        bool hasGps = Console.ReadLine().ToLower() == "так";

                        Console.WriteLine("Чи має монітор серця? (так/ні):");
                        bool hasHeartRateMonitor = Console.ReadLine().ToLower() == "так";

                        product = new SmartWatch(name, price, mechanism, brand, hasGps, hasHeartRateMonitor);
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
                    string randName = names[rand.Next(names.Length)];
                    decimal randPrice = prices[rand.Next(prices.Length)];
                    string randMechanism = mechanisms[rand.Next(mechanisms.Length)];
                    string randBrand = brands[rand.Next(brands.Length)];

                    Console.WriteLine("Виберіть тип годинників (1: Люксові, 2: Спортивні, 3: Смарт-годинники):");
                    string randType = Console.ReadLine();

                    if (randType == "1")
                    {
                        string randMaterial = materials[rand.Next(materials.Length)];
                        bool randLimitedEdition = limitedEditions[rand.Next(limitedEditions.Length)];

                        product = new LuxuryWatch(randName, randPrice, randMechanism, randBrand, randMaterial,
                            randLimitedEdition);
                    }
                    else if (randType == "2")
                    {
                        int randWaterRes = waterResistance[rand.Next(waterResistance.Length)];
                        bool randSmartFeatures = smartFeatures[rand.Next(smartFeatures.Length)];

                        product = new SportWatch(randName, randPrice, randMechanism, randBrand, randWaterRes,
                            randSmartFeatures);
                    }
                    else if (randType == "3")
                    {
                        bool randHasGps = smartFeatures[rand.Next(smartFeatures.Length)];
                        bool randHasHeartRateMonitor = smartFeatures[rand.Next(smartFeatures.Length)];

                        product = new SmartWatch(randName, randPrice, randMechanism, randBrand, randHasGps,
                            randHasHeartRateMonitor);
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
                    DisplayWatchesTable(products);
                    DisplayAccessoriesTable(products);

                    break;

                case "5":
                    Console.WriteLine("Виберіть тип аксесуара (1: Шкіряний, 2: Металевий):");
                    string accessoryType = Console.ReadLine();

                    if (accessoryType == "1")
                    {
                        Console.WriteLine("Введіть назву аксесуара:");
                        string accessoryName = Console.ReadLine();

                        Console.WriteLine("Введіть ціну аксесуара:");
                        decimal accessoryPrice = decimal.Parse(Console.ReadLine());

                        Console.WriteLine("Введіть тип аксесуара:");
                        string accessorySubType = Console.ReadLine();

                        Console.WriteLine("Введіть матеріал ремінця (Шкіра):");
                        string strapMaterial = "Шкіра";

                        Console.WriteLine("Має пряжку? (так/ні):");
                        bool hasBuckle = Console.ReadLine().ToLower() == "так";

                        product = new LeatherAccessory(accessoryName, accessoryPrice, accessorySubType, strapMaterial, hasBuckle);
                    }
                    else if (accessoryType == "2")
                    {
                        Console.WriteLine("Введіть назву аксесуара:");
                        string accessoryName = Console.ReadLine();

                        Console.WriteLine("Введіть ціну аксесуара:");
                        decimal accessoryPrice = decimal.Parse(Console.ReadLine());

                        Console.WriteLine("Введіть тип аксесуара:");
                        string accessorySubType = Console.ReadLine();

                        Console.WriteLine("Введіть тип металу (Нержавіюча сталь):");
                        string metalType = "Нержавіюча сталь";

                        Console.WriteLine("Полірований? (так/ні):");
                        bool isPolished = Console.ReadLine().ToLower() == "так";

                        product = new MetalAccessory(accessoryName, accessoryPrice, accessorySubType, metalType, isPolished);
                    }

                    if (product != null)
                    {
                        products.Add(product);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Аксесуар успішно додано!{RESET}");
                        Console.WriteLine($"\n{BRIGHT_YELLOW}Доданий аксесуар:{RESET}");
                        Console.WriteLine(product.ToString());
                    }

                    break;

                case "4":
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