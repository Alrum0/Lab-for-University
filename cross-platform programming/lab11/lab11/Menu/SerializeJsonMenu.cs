namespace lab5.Menu;

public static class SerializeMenuJson
{
    private const string BRIGHT_GREEN = "\u001b[92m";
    private const string BRIGHT_RED = "\u001b[91m";
    private const string RESET = "\u001b[0m";

    public static void Serialize(IContainer<IName> container)
    {
        Console.Write("Введіть ім'я файлу для збереження (наприклад: data.json): ");
        string fileName = Console.ReadLine();
        try
        {
            container.SerializeJson(fileName);
            Console.WriteLine($"{BRIGHT_GREEN}Контейнер успішно збережено у файл '{fileName}'!{RESET}");
            Console.WriteLine($"Шлях: {Path.Combine(Directory.GetCurrentDirectory(), fileName)}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{BRIGHT_RED}Помилка при збереженні: {ex.Message}{RESET}");
        }
    }

    public static IContainer<IName> Deserialize(IContainer<IName> currentContainer)
    {
        Console.Write("Введіть ім'я файлу для завантаження (наприклад: data.json): ");
        string fileName = Console.ReadLine();
        try
        {
            var loadedContainer = currentContainer.DeserializeFromFileJson(fileName);
            Console.WriteLine($"{BRIGHT_GREEN}Контейнер успішно завантажено з файлу '{fileName}'!{RESET}");
            return loadedContainer;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"{BRIGHT_RED}Помилка при завантаженні: {ex.Message}{RESET}");
            return currentContainer;
        }
    }
}