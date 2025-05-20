namespace lab5.Generators;

public class CreateWatch
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
    
    public static Product CreateWatchManually()
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
    
    public static Product CreateRandomWatch(Random rand)
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
}