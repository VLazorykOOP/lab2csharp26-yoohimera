using System;

class Program
{
    static void Main()
    {
        // 1. Введення розмірів матриці
        Console.Write("Введіть кількість рядків: ");
        int rows = int.Parse(Console.ReadLine());
        Console.Write("Введіть кількість стовпців: ");
        int cols = int.Parse(Console.ReadLine());

        int[,] matrix = new int[rows, cols];

        // 2. Заповнення матриці
        Console.WriteLine($"\nЗаповніть матрицю ({rows}x{cols}):");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write($"Елемент [{i},{j}]: ");
                matrix[i, j] = int.Parse(Console.ReadLine());
            }
        }

        // 3. Створення нового масиву для мінімальних значень
        // Його розмір дорівнює кількості стовпців (cols)
        int[] minArray = new int[cols];

        // 4. Пошук мінімуму в кожному стовпці
        for (int j = 0; j < cols; j++) // Цикл по стовпцях
        {
            int min = matrix[0, j]; // Припускаємо, що перший елемент стовпця — мінімальний
            for (int i = 1; i < rows; i++) // Перевіряємо інші елементи в цьому ж стовпці
            {
                if (matrix[i, j] < min)
                {
                    min = matrix[i, j];
                }
            }
            minArray[j] = min; // Записуємо знайдене мінімальне число в новий масив
        }

        // 5. Вивід результатів
        Console.WriteLine("\nВведена матриця:");
        PrintMatrix(matrix, rows, cols);

        Console.WriteLine("\nНовий масив (мінімуми кожного стовпця):");
        Console.WriteLine("[ " + string.Join(", ", minArray) + " ]");
    }

    static void PrintMatrix(int[,] matrix, int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
