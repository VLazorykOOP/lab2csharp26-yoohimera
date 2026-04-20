using System;
using System.Linq;

class Program
{
    static void Main()
    {
        // 1. Введення масиву
        Console.WriteLine("Введіть елементи масиву через пробіл:");
        string input = Console.ReadLine();
        int[] array = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
            .Select(int.Parse)
            .ToArray();

        // 2. Введення заданого числа (різниці)
        Console.Write("Введіть число (бажану різницю): ");
        int k = int.Parse(Console.ReadLine());

        int count = 0;

        // 3. Пошук пар сусідніх елементів
        // Цикл іде до Length - 1, щоб не вийти за межі масиву при зверненні до (i + 1)
        for (int i = 0; i < array.Length - 1; i++)
        {
            // Перевіряємо абсолютну різницю між сусідніми елементами
            if (Math.Abs(array[i] - array[i + 1]) == k)
            {
                count++;
                Console.WriteLine($"Знайдено пару: {array[i]} та {array[i + 1]} (індекси {i} та {i+1})");
            }
        }

        // 4. Вивід результату
        Console.WriteLine($"\nКількість пар із різницею {k}: {count}");

        Console.WriteLine("\nНатисніть будь-яку клавішу...");
        Console.ReadKey();ƒ
    }
}
