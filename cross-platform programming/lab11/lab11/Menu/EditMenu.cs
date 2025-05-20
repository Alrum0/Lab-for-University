using lab5;
using lab5.Views;
using lab5.Generators;
namespace lab5.Menu;

public class EditMenu
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
    
    public static void ShowEditMenu(IContainer<IName> products, int additionOrder)
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
                            newProduct = CreateWatch.CreateWatchManually();
                        }
                        else
                        {
                            newProduct = CreateAccessory.CreateAccessoryManually();
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
            
            Console.WriteLine($"\n{BRIGHT_YELLOW}Оновлений товар:{RESET}");
            ArrayContainer<IName> tempLinkedListContainer = new ArrayContainer<IName>();
            tempLinkedListContainer.Add(products[additionOrder]);
            DisplayTable.DisplayProductsTable(tempLinkedListContainer);
        }
    }
}