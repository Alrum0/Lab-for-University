namespace lab5.Menu;

public static class SerializeMenu
{
    private const string BRIGHT_GREEN = "\u001b[92m";
    private const string BRIGHT_RED = "\u001b[91m";
    private const string RESET = "\u001b[0m";

    public static void SerializeBinary(IContainer<IName> container)
    {
        Console.Write("Введіть ім'я бінарного файлу (наприклад: data.bin): ");
        string fileName = Console.ReadLine();
        try
        {
            (container as ArrayContainer<IName>)?.Serialize(fileName);
            Console.WriteLine($"{BRIGHT_GREEN}Контейнер збережено у файл '{fileName}'!{RESET}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{BRIGHT_RED}Помилка при збереженні: {ex.Message}{RESET}");
        }
    }

    public static IContainer<IName> DeserializeBinary()
    {
        Console.Write("Введіть ім'я бінарного файлу: ");
        string fileName = Console.ReadLine();
        try
        {
            var container = new ArrayContainer<IName>().DeserializeFromFile(fileName);
            Console.WriteLine($"{BRIGHT_GREEN}Контейнер відновлено з файлу '{fileName}'!{RESET}");
            return container;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{BRIGHT_RED}Помилка при завантаженні: {ex.Message}{RESET}");
            return new ArrayContainer<IName>();
        }
    }
}