namespace lab5.Generators;

public class CreateAccessory
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
    
    public static Product CreateAccessoryManually()
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
    
    public static Product CreateRandomAccessory(Random rand)
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
}