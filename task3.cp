using System;

class Program
{
    static void Main()
    {
        // 1. Введення розміру матриці
        Console.Write("Введіть розмір квадратної матриці (n): ");
        if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0)
        {
            Console.WriteLine("Помилка: введіть коректне ціле число більше 0.");
            return;
        }

        int[,] matrix = new int[n, n];

        // 2. Заповнення матриці користувачем
        Console.WriteLine($"\nВведіть елементи матриці ({n}x{n}):");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Console.Write($"Елемент [{i},{j}]: ");
                matrix[i, j] = int.Parse(Console.ReadLine());
            }
        }

        // 3. Обчислення
        double sum = 0;
        int count = 0;

        for (int i = 1; i < n; i++) // Рядки
        {
            for (int j = 0; j < i; j++) // Стовпці (тільки ті, що лівіше діагоналі)
            {
                if (matrix[i, j] % 2 == 0)
                {
                    sum += matrix[i, j];
                    count++;
                }
            }
        }

        // 4. Вивід результатів
        Console.WriteLine("\nВаша матриця:");
        PrintMatrix(matrix, n);

        Console.WriteLine("------------------------------------");
        if (count > 0)
        {
            double average = sum / count;
            Console.WriteLine($"Знайдено парних елементів під діагоналлю: {count}");
            Console.WriteLine($"Їхня сума: {sum}");
            Console.WriteLine($"Середнє арифметичне: {average:F2}");
        }
        else
        {
            Console.WriteLine("Парних елементів нижче головної діагоналі не знайдено.");
        }
    }

    // Допоміжний метод для гарного виводу матриці
    static void PrintMatrix(int[,] matrix, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
