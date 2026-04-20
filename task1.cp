using System;
using System.Linq;

class Program
{
    static void Main()
    {
        // 1. Введення масиву
        Console.WriteLine("Введіть елементи масиву через пробіл (наприклад: 10 2,5 30 5 18):");
        string input = Console.ReadLine();
        double[] array = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
            .Select(double.Parse)
            .ToArray();

        // 2. Введення меж інтервалу [a, b]
        Console.Write("Введіть початок інтервалу (a): ");
        double a = double.Parse(Console.ReadLine());
        
        Console.Write("Введіть кінець інтервалу (b): ");
        double b = double.Parse(Console.ReadLine());

        // Перевірка, щоб a було менше за b
        if (a > b)
        {
            double temp = a;
            a = b;
            b = temp;
        }

        Console.WriteLine($"\nНомери елементів, що не потрапляють в інтервал [{a}; {b}]:");
        bool found = false;

        // 3. Пошук елементів поза інтервалом
        for (int i = 0; i < array.Length; i++)
        {
            // Елемент не потрапляє в інтервал, якщо він менший за 'a' АБО більший за 'b'
            if (array[i] < a || array[i] > b)
            {
                // Виводимо номер (i + 1), якщо рахувати з одиниці, або просто i
                Console.Write($"{i + 1} "); 
                found = true;
            }
        }

        if (!found)
        {
            Console.WriteLine("Усі елементи знаходяться всередині інтервалу.");
        }

        Console.WriteLine("\n\nНатисніть будь-яку клавішу для виходу...");
        Console.ReadKey();
    }
}
