using lab5.Views;

namespace lab5.Menu;


public class NewFunctionForContainer
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
    
     public static void ShowHelpMenu(IContainer<IName> products)
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

            IContainer<IName> searchResults = new LinkedListContainer<IName>();
            List<int> originalIndices = new List<int>();

            switch (helpChoice)
            {
                case "1":
                    DisplayTable.DisplayProductsTable(products);
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
                    DisplayTable.DisplayProductsTable(products);
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
                    DisplayTable.DisplayProductsTable(products);
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
            DisplayTable.DisplayProductsTable(searchResults);
            
            Console.WriteLine("\nВведіть номер товару для редагування (або 0 для повернення):");
            if (int.TryParse(Console.ReadLine(), out int editChoice) && editChoice > 0 && editChoice <= searchResults.Count)
            {
                int originalIndex = originalIndices[editChoice - 1];
                EditMenu.ShowEditMenu(products, originalIndex);
            }
            else if (editChoice != 0)
            {
                Console.WriteLine($"{RED}\nНевірний номер товару!{RESET}");
                Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
                Console.ReadKey();
            }
        }
    }
}