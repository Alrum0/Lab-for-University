using lab5.Views;

namespace lab5.Menu;

public class DeleteProductMenu
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
    
    public static void DeleteProduct(IContainer<IName> products)
    {
        if (products.Count == 0)
        {
            Console.WriteLine("\nНемає товарів для видалення.");
            return;
        }
                    
        DisplayTable.DisplayProductsTable(products);
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
    }
}