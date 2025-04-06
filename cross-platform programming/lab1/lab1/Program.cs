class Program {
    static bool GetUniqueChar(string word)
    {
        List<char> chars = new List<char>();
        for(int i = 0; i < word.Length; i++) {
            char c = word[i];
            if (chars.Contains(c))
                return false;
            chars.Add(c);
        }
        return true;
    }
    
    static void Main()
    {
        Console.WriteLine("Введіть рядок:");
        string input = Console.ReadLine();
        
        string[] words = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        
        var filteredWords = words.Where(GetUniqueChar);
        
        Console.WriteLine("Результат:");
        Console.WriteLine(string.Join(" ", filteredWords));
    }
}