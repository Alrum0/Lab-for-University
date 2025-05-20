namespace lab5.Menu;
using lab5.Views;
public class DelegateOperationsMenu
{
    public static void ShowMenu(IContainer<IName> products)
    {
        Console.Clear();
        Console.WriteLine("1. Знайти перший товар за умовою(Годиник)");
        Console.WriteLine("2. Знайти всі товари за умовою(Годиник)");
        Console.WriteLine("3. Сортування");

        Console.Write("Ваш вибір: ");
        string choice = Console.ReadLine();

        switch (choice)
        {
            case "1":
                var found = products.Find(p => p is Watch);
                if (found != null)
                {
                    var tempContainer = new ArrayContainer<IName>();
                    tempContainer.Add(found);
                    Console.WriteLine("\nЗнайдено товар:");
                    DisplayTable.DisplayProductsTable(tempContainer);
                }
                else
                {
                    Console.WriteLine("Нічого не знайдено.");
                }
                break;

            case "2":
                var all = products.FindAll(p => p is Watch);
                if (all.Count > 0)
                {
                    var tempContainer = new ArrayContainer<IName>();
                    foreach (var item in all)
                        tempContainer.Add(item);
                    Console.WriteLine("\nЗнайдені товари:");
                    DisplayTable.DisplayProductsTable(tempContainer);
                }
                else
                {
                    Console.WriteLine("Нічого не знайдено.");
                }
                break;

            case "3":
                Console.WriteLine("\nСортувати за:");
                Console.WriteLine("1. Назвою");
                Console.WriteLine("2. Ціною");
                Console.Write("Ваш вибір: ");
                string sortField = Console.ReadLine();

                Console.WriteLine("Сортувати у:");
                Console.WriteLine("1. За зростанням");
                Console.WriteLine("2. За спаданням");
                Console.Write("Ваш вибір: ");
                string sortOrder = Console.ReadLine();

                Comparison<IName>? comparison = null; 

                switch (sortField)
                {
                    case "1": 
                        comparison = (a, b) => a.Name.CompareTo(b.Name);
                        break;

                    case "2": 
                        comparison = (a, b) => a.Price.CompareTo(b.Price);
                        break;

                    default:
                        Console.WriteLine("Невірне поле для сортування.");
                        break;
                }

                if (comparison == null)
                    break;

                switch (sortOrder)
                {
                    case "1": 
                        break;

                    case "2": 
                        var original = comparison;
                        comparison = (a, b) => original(b, a);
                        break;

                    default:
                        Console.WriteLine("Невірний напрямок сортування.");
                        break;
                }

                products.Sort(comparison);
                Console.WriteLine("Список відсортовано.");
                DisplayTable.DisplayProductsTable(products);
                break;

            default:
                Console.WriteLine("Невірний вибір.");
                break;
        }
    }
}