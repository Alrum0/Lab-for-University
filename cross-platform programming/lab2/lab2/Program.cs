
class Program
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
    
    static void Main()  
    {
        bool exit = false;
        while (!exit)
        {
            Console.Clear();
            Console.WriteLine($"{TABUL} {BRIGHT_BLUE}Робота з рваним масивом (ﾉ\u25d5ヮ\u25d5)ﾉ{RESET}");
            Console.WriteLine("1. Ввести масив самому");
            Console.WriteLine("2. Згенерувати випадковий масив");
            Console.WriteLine($"{RED}3. Вихід{RESET}");
            Console.Write($"{BRIGHT_YELLOW}Виберіть опцію: {RESET}");

            switch (Console.ReadLine())
            {
                case "1":
                    UserInput();
                    break;
                case "2":
                    RandomArray();
                    break;
                case "3":
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Невірний вибір. Натисніть будь-яку клавішу для продовження...");
                    Console.ReadKey();
                    break;
            }
        }
    }
    static void UserInput()
    {
        Console.Clear();
        Console.Write($"{BRIGHT_YELLOW}Введіть кількість рядків: {RESET}");
        int rows = int.Parse(Console.ReadLine());

        int[][] jaggedArray = new int[rows][];

        for (int i = 0; i < rows; i++)
        {
            Console.Write($"Введіть елементи рядка {i + 1} (через пробіл): ");
            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            jaggedArray[i] = new int[input.Length];

            for (int j = 0; j < input.Length; j++)
            {
                jaggedArray[i][j] = int.Parse(input[j]);
            }
        }

        SomeFunction(jaggedArray);
    }
    static void RandomArray()
    {
        Console.Clear();
        Console.Write("Введіть кількість рядків: ");
        int rows = int.Parse(Console.ReadLine());
        
        Random random = new Random();
        int[][] jaggedArray = new int[rows][];

        for (int i = 0; i < rows; i++)
        {
            int length = random.Next(1, 20); 
            jaggedArray[i] = new int[length];

            for (int j = 0; j < length; j++)
            {
                jaggedArray[i][j] = random.Next(-10, 15); 
            }
        }

        SomeFunction(jaggedArray);
    }
    static void PrintArray(int[][] array, int maxSumRowIndex = -1, int insertedRowIndex = -1)
    {
        for (int i = 0; i < array.Length; i++)
        {
            if (i == maxSumRowIndex)
            {
                Console.Write($"Рядок {i + 1}: {BRIGHT_GREEN}");
            }
            else if (i == insertedRowIndex)
            {
                Console.Write($"Рядок {i + 1}: {RED}");
            }
            else
            {
                Console.Write($"Рядок {i + 1}: ");
            }

            foreach (int element in array[i])
            {
                Console.Write($"{element} ");
            }
            Console.WriteLine($"Сума:{BRIGHT_GREEN} {CalculateRowSum(array[i])}{RESET}");
        }
    }
    static void SomeFunction(int[][] array)
    {
        Console.WriteLine($"{BRIGHT_BLUE}\nПочатковий масив:{RESET}");
        PrintArray(array); 
        
        int maxSumRowIndex = FindMaxSum(array);
        int minSumRowIndex = FindMinSum(array);

        int maxSum = CalculateRowSum(array[maxSumRowIndex]);
        Console.WriteLine($"\nРядок з максимальною сумою ({BRIGHT_GREEN}{maxSum}{RESET}) має рядок {maxSumRowIndex + 1}");
        
        int minSum = CalculateRowSum(array[minSumRowIndex]);
        Console.WriteLine($"Рядок з мінімальною сумою ({BRIGHT_GREEN}{minSum}{RESET}) має рядок {minSumRowIndex + 1}");
        
        int[][] newArray = InsertMinAfterMax(array, maxSumRowIndex, minSumRowIndex);
        
        Console.WriteLine($"{BRIGHT_BLUE}\nНовий масив після вставки:{RESET}");
        PrintArray(newArray, maxSumRowIndex, maxSumRowIndex + 1); 

        Console.WriteLine("\nНатисніть будь-яку клавішу для повернення до меню...");
        Console.ReadKey();
    }
    static int CalculateRowSum(int[] row)
    {
        int sum = 0;
        foreach (int element in row)
        {
            sum += element;
        }
        return sum;
    }
    static int FindMaxSum(int[][] array)
    {
        int maxSumIndex = 0;
        int maxSum = CalculateRowSum(array[0]);

        for (int i = 1; i < array.Length; i++)
        {
            int currentSum = CalculateRowSum(array[i]);
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                maxSumIndex = i;
            }
        }
        return maxSumIndex;
    }
    static int FindMinSum(int[][] array)
    {
        int minSumIndex = 0;
        int minSum = CalculateRowSum(array[0]);

        for (int i = 1; i < array.Length; i++)
        {
            int currentSum = CalculateRowSum(array[i]);
            if (currentSum < minSum)
            {
                minSum = currentSum;
                minSumIndex = i;
            }
        }
        return minSumIndex;
    }
    static int[][] InsertMinAfterMax(int[][] array, int maxSumRowIndex, int minSumRowIndex)
    {
        int[][] newArray = new int[array.Length + 1][];
        
        for (int i = 0; i <= maxSumRowIndex; i++)
        {
            newArray[i] = new int[array[i].Length + 1];
            for (int j = 0; j < array[i].Length; j++)
            {
                newArray[i][j] = array[i][j];
            }
        }
        newArray[maxSumRowIndex + 1] = new int[array[minSumRowIndex].Length];
        for (int j = 0; j < array[minSumRowIndex].Length; j++)
        {
            newArray[maxSumRowIndex + 1][j] = array[minSumRowIndex][j];
        }
        for (int i = maxSumRowIndex + 1; i < array.Length; i++)
        {
            newArray[i + 1] = new int[array[i].Length];
            for (int j = 0; j < array[i].Length; j++)
            {
                newArray[i + 1][j] = array[i][j];
            }
        }
        return newArray;
    }
}