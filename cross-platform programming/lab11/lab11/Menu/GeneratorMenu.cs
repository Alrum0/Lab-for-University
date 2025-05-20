namespace lab5.Menu;
using lab5.Views;

public class GeneratorMenu
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
    
    public static void GeneratorOperationsMenu(IContainer<IName> container)
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine($"{TABUL}{BRIGHT_BLUE}Робота з генераторами:{RESET}");
            Console.WriteLine("1. Вивести товари у зворотньому порядку");
            Console.WriteLine("2. Пошук товарів за підрядком");
            Console.WriteLine("3. Відсортовані товари за назвою (генератор)");
            Console.WriteLine("4. Відсортовані товари за ціною (генератор)");
            Console.WriteLine($"{RED}5. Повернутись до головного меню{RESET}");
            
            Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1": 
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Товари у зворотньому порядку:{RESET}");
                    DisplayProductsTableForGenerat.DisplayProductsTableForGenerate(container.GetReverseOrder(), true);
                    break;
                    
                case "2": 
                    Console.WriteLine("Введіть підрядок для пошуку:");
                    string substring = Console.ReadLine();
                    if (!string.IsNullOrWhiteSpace(substring))
                    {
                        Console.WriteLine($"\n{BRIGHT_YELLOW}Результати пошуку за '{substring}':{RESET}");
                        DisplayProductsTableForGenerat.DisplayProductsTableForGenerate(container.GetItemsWithSubstring(substring));
                    }
                    else
                    {
                        Console.WriteLine($"{RED}Підрядок не може бути порожнім!{RESET}");
                    }
                    break;
                    
                case "3": 
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Товари відсортовані за назвою:{RESET}");
                    DisplayProductsTableForGenerat.DisplayProductsTableForGenerate(container.GetOrderedByName());
                    break;
                    
                case "4": 
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Товари відсортовані за ціною:{RESET}");
                    DisplayProductsTableForGenerat.DisplayProductsTableForGenerate(container.GetOrderedByPrice());
                    break;
                    
                case "5": 
                    return;
                    
                default:
                    Console.WriteLine($"{RED}Невірний вибір, спробуйте ще раз.{RESET}");
                    break;
            }
            
            Console.WriteLine("\nНатисніть будь-яку клавішу для продовження...");
            Console.ReadKey();
        }
    }
}