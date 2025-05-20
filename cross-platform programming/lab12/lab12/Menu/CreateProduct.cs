using lab5.Generators;

namespace lab5.Menu;

public class CreateProduct
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
    
    public static void ManualInput(IContainer<IName> products)
    {
        
        Console.WriteLine("Виберіть тип товару (1: Годинник, 2: Аксесуар):");
        string productType = Console.ReadLine();
        Product product = null;

        if (productType == "1")
        {
            product = CreateWatch.CreateWatchManually();
        }
        else if (productType == "2")
        {
            product = CreateAccessory.CreateAccessoryManually();
        }
        else
        {
            Console.WriteLine("Невірний вибір типу товару.");
            return;
        }

        if (product != null)
        {
            products.Add(product);
            Console.WriteLine($"\n{BRIGHT_GREEN}Товар успішно додано!{RESET}");
            Console.WriteLine($"\n{BRIGHT_YELLOW}Доданий товар:{RESET}");
            Console.WriteLine(product.ToString());
        }
    }

    public static void RandomInput(IContainer<IName> products)
    {
        Random rand = new Random();
        Console.WriteLine("Введіть кількість товарів для генерації:");
        Product product = null;
        if (int.TryParse(Console.ReadLine(), out int count) && count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                int randomProductType = rand.Next(1, 3);
            
                if (randomProductType == 1)
                {
                    product = CreateWatch.CreateRandomWatch(rand);
                }
                else
                {
                    product = CreateAccessory.CreateRandomAccessory(rand);
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
    }
}