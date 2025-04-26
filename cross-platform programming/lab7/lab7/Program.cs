namespace lab5;

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
    
    //функція для відображення таблиці
    
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
        const int col9Width = 16;
        
        // border
        
        string separator = new string('-', 
            col1Width + col2Width + col3Width + col4Width + col5Width + 
            col6Width + col7Width + col8Width + col9Width + 28);

        Console.WriteLine($"\n" + separator);
        Console.WriteLine(
            $"| {$"{BRIGHT_YELLOW}№ п/п".PadRight(col1Width)} " +
            $"| {"Назва".PadRight(col2Width)} " +
            $"| {"Ціна".PadRight(col3Width)} " +
            $"| {"Тип".PadRight(col4Width)} " +
            $"| {"Механізм".PadRight(col5Width)} " +
            $"| {"Бренд".PadRight(col6Width)} " +
            $"| {"Матеріал".PadRight(col7Width)} " +
            $"| {"Водозахист".PadRight(col8Width)} " +
            $"| {"Функції ".PadRight(col9Width)} |{RESET}");
        Console.WriteLine(separator);

        for (int i = 0; i < products.Count; i++)
        {
            IName product = products.GetAt(i);
            string num = products.GetAdditionOrderAt(i).ToString();
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
    
    //функція для ствоення товару аксесуара
    
    static Product CreateAccessoryManually()
    {
        try
        {
            Console.WriteLine("Введіть назву аксесуара:");
            string name = Console.ReadLine();
            if (string.IsNullOrEmpty(name))
                throw new InvalidProductDataException($"{RED}Назва не може бути порожньою{RESET}");

            Console.WriteLine("Введіть ціну:");
            string priceInput = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(priceInput))
                throw new InvalidProductDataException($"{RED}Ціна не може бути порожньою{RESET}");
        
            if (!decimal.TryParse(priceInput, out decimal price))
                throw new InvalidProductDataException($"{RED}Ціна має бути коректним числом{RESET}");
        
            Console.WriteLine("Виберіть тип аксесуара (1: Шкіряний, 2: Металевий):");
            string accessoryChoice = Console.ReadLine();
            if (string.IsNullOrEmpty(accessoryChoice))
                throw new InvalidProductDataException($"{RED}Тип не може бути порожнім{RESET}");
        
            if (accessoryChoice == "1")
            {
                Console.WriteLine("Введіть тип аксесуара (наприклад, Ремінець, Браслет):");
                string type = Console.ReadLine();
                if (string.IsNullOrEmpty(type))
                    throw new InvalidProductDataException($"{RED}Тип не може бути порожнім{RESET}");

                Console.WriteLine("Введіть матеріал ремінця (Шкіра, Екошкіра тощо):");
                string strapMaterial = Console.ReadLine();
                if (string.IsNullOrEmpty(strapMaterial))
                    throw new InvalidProductDataException($"{RED}Матеріал не може бути порожнім{RESET}");

                Console.WriteLine("Має пряжку? (так/ні):");
                string inputBuckle = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(inputBuckle))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (inputBuckle.ToLower() != "так" && inputBuckle.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool hasBuckle = inputBuckle.ToLower() == "так";

                return new LeatherAccessory(name, price, type, strapMaterial, hasBuckle);
            }
            else if (accessoryChoice == "2")
            {
                Console.WriteLine("Введіть тип аксесуара (наприклад: Браслет, Ланцюжок):");
                string type = Console.ReadLine();
                if (string.IsNullOrEmpty(type))
                    throw new InvalidProductDataException($"{RED}Тип не може бути порожнім{RESET}");

                Console.WriteLine("Введіть тип металу (Нержавіюча сталь, Срібло тощо):");
                string metalType = Console.ReadLine();
                if (string.IsNullOrEmpty(metalType))
                    throw new InvalidProductDataException($"{RED}Тип металу не може бути порожнім{RESET}");

                Console.WriteLine("Полірований? (так/ні):");
                string inputPolished = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(inputPolished))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (inputPolished.ToLower() != "так" && inputPolished.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool isPolished = inputPolished.ToLower() == "так";

                return new MetalAccessory(name, price, type, metalType, isPolished);
            }
            else
            {
                throw new InvalidProductDataException($"{RED}Невірний тип аксесуара. Оберіть 1 або 2{RESET}");
            }
        }
        catch (InvalidProductDataException ex)
        {
            Console.WriteLine($"{RED}Помилка: {ex.Message}{RESET}\n{YELLOW}Спробуйте ще раз\n{RESET}");
        }
        return null;
    }
    
    //функція для створення часів вручну
    
    static Product CreateWatchManually()
    {
        try
        {
            Console.WriteLine("Введіть назву годинника:");
            string name = Console.ReadLine();
            if (string.IsNullOrEmpty(name))
                throw new InvalidProductDataException($"{RED}Назва не може бути порожньою{RESET}");
            
            Console.WriteLine("Введіть ціну:");
            string priceInput = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(priceInput))
                throw new InvalidProductDataException($"{RED}Ціна не може бути порожньою{RESET}");
        
            if (!decimal.TryParse(priceInput, out decimal price))
                throw new InvalidProductDataException($"{RED}Ціна має бути коректним числом{RESET}");


            Console.WriteLine("Введіть механізм (Механічний, Кварцовий, Автоматичний):");
            string mechanism = Console.ReadLine();
            if (string.IsNullOrEmpty(mechanism))
                throw new InvalidProductDataException($"{RED}Тип механізму не може бути порожнім{RESET}");
            
            Console.WriteLine("Введіть бренд:");
            string brand = Console.ReadLine();
            if (string.IsNullOrEmpty(brand))
                throw new InvalidProductDataException($"{RED}Бренд не може бути порожнім{RESET}");
            
            Console.WriteLine("Виберіть тип годинників (1: Люксові, 2: Спортивні, 3: Смарт-годинники):");
            string type = Console.ReadLine();
            if (string.IsNullOrEmpty(type))
                throw new InvalidProductDataException($"{RED}Тип не може бути порожнім{RESET}");

            if (type == "1")
            {
                Console.WriteLine("Введіть матеріал (Золото, Платина, Титан):");
                string material = Console.ReadLine();
                if (string.IsNullOrEmpty(material))
                    throw new InvalidProductDataException($"{RED}Матеріал не може бути порожнім{RESET}");

                Console.WriteLine("Обмежений випуск? (так/ні):");
                string inputLimitedEffition = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(inputLimitedEffition))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (inputLimitedEffition.ToLower() != "так" && inputLimitedEffition.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool limitedEdition = inputLimitedEffition.ToLower() == "так";

                return new LuxuryWatch(name, price, mechanism, brand, material, limitedEdition);
            }
            else if (type == "2")
            {
                Console.WriteLine("Введіть водозахист у метрах:");
                string waterInput = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(waterInput))
                    throw new InvalidProductDataException($"{RED}Водозахист не може бути порожнім{RESET}");
                if (!int.TryParse(waterInput, out int waterRes))
                    throw new InvalidProductDataException($"{RED}Водозахист має бути цілим числом{RESET}");

                Console.WriteLine("Чи має розумні функції? (так/ні):");
                string inputChoice = Console.ReadLine();
                
                if (string.IsNullOrWhiteSpace(inputChoice))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (inputChoice.ToLower() != "так" && inputChoice.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool hasSmartFeaturesChoice = inputChoice.ToLower() == "так";
                
                return new SportWatch(name, price, mechanism, brand, waterRes, hasSmartFeaturesChoice);
            }
            else if (type == "3")
            {
                Console.WriteLine("Чи має GPS? (так/ні):");
                string gpsInput = Console.ReadLine();
                
                if (string.IsNullOrWhiteSpace(gpsInput))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (gpsInput.ToLower() != "так" && gpsInput.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool hasGps = gpsInput.ToLower() == "так";

                Console.WriteLine("Чи має монітор серця? (так/ні):");

                string inputHeartRateMonitor = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(inputHeartRateMonitor))
                {
                    throw new InvalidProductDataException($"{RED}Відповідь не може бути порожньою{RESET}");
                }
                
                if (inputHeartRateMonitor.ToLower() != "так" && inputHeartRateMonitor.ToLower() != "ні")
                {
                    throw new InvalidProductDataException($"{RED}Будь ласка, введіть 'так' або 'ні'{RESET}");
                }

                bool hasHeartRateMonitor = inputHeartRateMonitor.ToLower() == "так";

                return new SmartWatch(name, price, mechanism, brand, hasGps, hasHeartRateMonitor);
            }
            else
            {
                throw new InvalidProductDataException($"{RED}Невірний тип годинника. Оберіть 1, 2 або 3{RESET}");
            }

        }
        catch (InvalidProductDataException ex)
        {
            Console.WriteLine($"{RED}Помилка: {ex.Message}{RESET}\n{YELLOW}Спробуйте ще раз\n{RESET}");
        }
            return null;
    }
    
    //функція для створення рандомнних аксес
    
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
    
    //функція для створення рандомнних часів
    
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
    
    //вибір сортування для ціни
    
    private static string GetSortOrderText(bool ascending)
    {
        return ascending ? "за зростанням" : "за спаданням";
    }


    //Допоміжна менюшка для лабораторної роботи номер 5

    static void ShowHelpMenu(Container products)
{
    while (true)
    {
        Console.Clear();
        Console.WriteLine($"{TABUL}{BRIGHT_BLUE}Довідка - нові функції контейнера:{RESET}");
        Console.WriteLine("1. Пошук за порядковим номером додавання");
        Console.WriteLine("2. Пошук за назвою товару");
        Console.WriteLine("3. Пошук за ціною");
        Console.WriteLine("4. Повернутися до головного меню");
        
        Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
        string helpChoice = Console.ReadLine();

        if (helpChoice == "4") return;

        if (products.Count == 0)
        {
            Console.WriteLine($"{RED}\nКонтейнер порожній!{RESET}");
            Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
            Console.ReadKey();
            continue;
        }

        Container searchResults = new Container();
        List<int> originalIndices = new List<int>();

        switch (helpChoice)
        {
            case "1":
                DisplayProductsTable(products);
                Console.WriteLine("\nВведіть порядковий номер додавання (1 - {0}):", products.Count);
                if (int.TryParse(Console.ReadLine(), out int orderNum) && orderNum >= 1 && orderNum <= products.Count)
                {
                    try
                    {
                        IName found = products[orderNum];
                        searchResults.Add(found);
                        originalIndices.Add(orderNum);
                    }
                    catch (InvalidProductDataException ex)
                    {
                        Console.WriteLine($"{RED}\nПомилка: {ex.Message}{RESET}");
                        Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                        Console.ReadKey();
                        continue;
                    }
                }
                else
                {
                    Console.WriteLine($"{RED}\nНевірний номер!{RESET}");
                    Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                    Console.ReadKey();
                    continue;
                }
                break;

            case "2":
                DisplayProductsTable(products);
                Console.WriteLine("\nВведіть назву товару для пошуку:");
                string nameToFind = Console.ReadLine();
                
                try
                {
                    var allWithName = products.GetAllByName(nameToFind).ToList();
                    if (allWithName.Count == 0)
                    {
                        Console.WriteLine($"{RED}\nТоварів з назвою '{nameToFind}' не знайдено!{RESET}");
                        Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                        Console.ReadKey();
                        continue;
                    }

                    foreach (var product in allWithName)
                    {
                        searchResults.Add(product);
                        originalIndices.Add(products.GetAdditionOrder(product));
                    }
                }
                catch (InvalidProductDataException ex)
                {
                    Console.WriteLine($"{RED}\nПомилка: {ex.Message}{RESET}");
                    Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                    Console.ReadKey();
                    continue;
                }
                break;

            case "3":
                DisplayProductsTable(products);
                Console.WriteLine("\nВведіть ціну для пошуку:");
                if (decimal.TryParse(Console.ReadLine(), out decimal priceToFind))
                {
                    try
                    {
                        var allWithPrice = products.GetAllByPrice(priceToFind).ToList();
                        if (allWithPrice.Count == 0)
                        {
                            Console.WriteLine($"{RED}\nТоварів з ціною {priceToFind} не знайдено!{RESET}");
                            Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                            Console.ReadKey();
                            continue;
                        }

                        foreach (var product in allWithPrice)
                        {
                            searchResults.Add(product);
                            originalIndices.Add(products.GetAdditionOrder(product));
                        }
                    }
                    catch (InvalidProductDataException ex)
                    {
                        Console.WriteLine($"{RED}\nПомилка: {ex.Message}{RESET}");
                        Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                        Console.ReadKey();
                        continue;
                    }
                }
                else
                {
                    Console.WriteLine($"{RED}\nНевірний формат ціни!{RESET}");
                    Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                    Console.ReadKey();
                    continue;
                }
                break;

            default:
                Console.WriteLine($"{RED}\nНевірний вибір!{RESET}");
                Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                Console.ReadKey();
                continue;
        }
        
        Console.Clear();
        Console.WriteLine($"{BRIGHT_GREEN}Результати пошуку:{RESET}");
        DisplayProductsTable(searchResults);
        
        Console.WriteLine("\nВведіть номер товару для редагування (або 0 для повернення):");
        if (int.TryParse(Console.ReadLine(), out int editChoice) && editChoice > 0 && editChoice <= searchResults.Count)
        {
            int originalIndex = originalIndices[editChoice - 1];
            ShowEditMenu(products, originalIndex);
        }
        else if (editChoice != 0)
        {
            Console.WriteLine($"{RED}\nНевірний номер товару!{RESET}");
            Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
            Console.ReadKey();
        }
    }
}

// Новий метод для відображення меню редагування
static void ShowEditMenu(Container products, int additionOrder)
{
    IName product = products[additionOrder];
    
    while (true)
    {
        Console.WriteLine($"\n{BRIGHT_BLUE}Редагування товару (№{additionOrder}):{RESET}");
        Console.WriteLine("1. Змінити назву");
        Console.WriteLine("2. Змінити ціну");
        Console.WriteLine("3. Змінити тип");
        Console.WriteLine("4. Повернутися до попереднього меню");
        
        Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
        string editChoice = Console.ReadLine();

        switch (editChoice)
        {
            case "1":
                Console.WriteLine("Поточна назва: " + product.Name);
                Console.WriteLine("Введіть нову назву:");
                string newName = Console.ReadLine();
                product.Name = newName;
                products[additionOrder] = product; 
                Console.WriteLine($"{BRIGHT_GREEN}Назву змінено успішно!{RESET}");
                break;
                
            case "2":
                Console.WriteLine("Поточна ціна: " + product.Price);
                Console.WriteLine("Введіть нову ціну:");
                if (decimal.TryParse(Console.ReadLine(), out decimal newPrice))
                {
                    product.Price = newPrice;
                    products[additionOrder] = product;
                    Console.WriteLine($"{BRIGHT_GREEN}Ціну змінено успішно!{RESET}");
                }
                else
                {
                    Console.WriteLine($"{RED}Невірний формат ціни!{RESET}");
                }
                break;
                
            case "3":
                Console.WriteLine("Поточний тип: " + product.GetType().Name);
                Console.WriteLine("Оберіть новий тип:");
                Console.WriteLine("1. Годинник");
                Console.WriteLine("2. Аксесуар");
                Console.WriteLine("3. Скасувати");
                
                string typeChoice = Console.ReadLine();
                if (typeChoice == "1" || typeChoice == "2")
                {
                    Product newProduct;
                    if (typeChoice == "1")
                    {
                        newProduct = CreateWatchManually();
                    }
                    else
                    {
                        newProduct = CreateAccessoryManually();
                    }
                    newProduct.Name = product.Name; 
                    newProduct.Price = product.Price; 
                    products[additionOrder] = newProduct;
                    Console.WriteLine($"{BRIGHT_GREEN}Тип товару змінено успішно!{RESET}");
                }
                break;
                
            case "4":
                return;
                
            default:
                Console.WriteLine($"{RED}Невірний вибір!{RESET}");
                break;
        }
        
        // Показуємо оновлений товар
        Console.WriteLine($"\n{BRIGHT_YELLOW}Оновлений товар:{RESET}");
        Container tempContainer = new Container();
        tempContainer.Add(products[additionOrder]);
        DisplayProductsTable(tempContainer);
    }
}

// Перевантажений варіант для пошуку за ім'ям
static void ShowEditMenu(Container products, string name)
{
    int order = products.GetAdditionOrder(products[name]);
    ShowEditMenu(products, order);
}
    
    //Основна функція main
    
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
            Console.WriteLine("6. Довідка (нові функції)");
            Console.WriteLine($"{RED}7. Вихід{RESET}");

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
                    Console.WriteLine("Введіть кількість товарів для генерації:");
                    if (int.TryParse(Console.ReadLine(), out int count) && count > 0)
                    {
                        for (int i = 0; i < count; i++)
                        {
                            int randomProductType = rand.Next(1, 3);
            
                            if (randomProductType == 1)
                            {
                                product = CreateRandomWatch(rand);
                            }
                            else
                            {
                                product = CreateRandomAccessory(rand);
                            }

                            if (product != null)
                            {
                                products.Add(product);
                            }
                        }
                        Console.WriteLine($"\n{BRIGHT_GREEN}Успішно згенеровано {count} товарів!{RESET}");
                        
                    }
                    else
                    {
                        Console.WriteLine($"{RED}\nНевірна кількість товарів!{RESET}");
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
                        products.SortByName(true); 
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
                    ShowHelpMenu(products);
                    break;
                
                case "7":
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