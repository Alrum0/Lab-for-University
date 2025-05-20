using lab5.Views;

namespace lab5.Menu;

public class SortMenuForTable
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
    
    public static void SortMenu(IContainer<IName> products)
    {
        if (products.Count == 0)
                    {
                        Console.WriteLine("\nНемає товарів для сортування.");
                        return;
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
                        DisplayTable.DisplayProductsTable(products);
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
                            return;
                        }

                        bool ascending = sortOrderChoice == "1";
                        products.SortByPrice(ascending);
                        Console.WriteLine($"\n{BRIGHT_GREEN}Товари успішно відсортовані за ціною ({GetSortOrderText(ascending)})!{RESET}");
                        DisplayTable.DisplayProductsTable(products);
                    }
                    else
                    {
                        Console.WriteLine($"\n{BRIGHT_RED}Невірний вибір критерію сортування!{RESET}");
                    }
        
                    static string GetSortOrderText(bool ascending)
                    {
                        return ascending ? "за зростанням" : "за спаданням";
                    }
    }
}