namespace lab5;
using Views;
using lab5.Menu;

public static class Program
{
    const string BRIGHT_YELLOW = "\u001b[93m";
    const string BRIGHT_BLUE = "\u001b[94m";
    const string RESET = "\u001b[0m";
    const string RED = "\u001b[31m";
    const string TABUL = "\t\t\t\t\t\t\t";
    
    static void Main()
    {
        bool exit = false;

        Console.WriteLine($"{TABUL}{BRIGHT_BLUE}Оберіть тип контейнера:{RESET}");
        Console.WriteLine("1. Масив");
        Console.WriteLine("2. Двозв'язний список");
        Console.Write("Ваш вибір: ");
    
        string containerChoice = Console.ReadLine();
        IContainer<IName> products;

        if (containerChoice == "1")
            products = new ArrayContainer<IName>();
        else if (containerChoice == "2")
            products = new LinkedListContainer<IName>();
        else
        {
            Console.WriteLine("Невірний вибір. Використовується LinkedListContainer за замовчуванням.");
            products = new LinkedListContainer<IName>();
        }

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
            Console.WriteLine("7. переглянути через foreach");
            Console.WriteLine("8. Робота з генераторами");
            Console.WriteLine("9. Зберегти контейнер у файл");
            Console.WriteLine("10. Завантажити контейнер з файлу");
            Console.WriteLine("11. Зберегти контейнер у файл(json)");
            Console.WriteLine("12. Завантажити контейнер з файлу(json)");
            Console.WriteLine($"{RED}13. Вихід{RESET}");

            Console.Write($"{BRIGHT_YELLOW}Ваш вибір: {RESET}");
            string choice = Console.ReadLine();
            Product product = null;

            switch (choice)
            {
                case "1":
                    CreateProduct.ManualInput(products);
                    break;

                case "2":
                    CreateProduct.RandomInput(products);
                    break;

                case "3":
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Список усіх створених товарів:{RESET}");
                    DisplayTable.DisplayProductsTable(products);
                    break;
                    
                case "4":
                    DeleteProductMenu.DeleteProduct(products);
                    break;

                case "5":
                    SortMenuForTable.SortMenu(products);
                    break;
                
                case "6":
                    NewFunctionForContainer.ShowHelpMenu(products);
                    break;
                case "7":
                    Console.WriteLine($"\n{BRIGHT_YELLOW}Список усіх створених товарів (через foreach):{RESET}");
                    DisplayProductsTableWithForeachh.DisplayProductsTableWithForeach(products);
                    break;
                case "8":
                    GeneratorMenu.GeneratorOperationsMenu(products);
                    break;
                case "9":
                    SerializeMenu.SerializeBinary(products);
                    break;
                case "10":
                    products = SerializeMenu.DeserializeBinary();
                    break;
                case "11":
                    SerializeMenuJson.Serialize(products);
                    break;
                case "12":
                    products = SerializeMenuJson.Deserialize(products);
                    break;
                case "13":
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