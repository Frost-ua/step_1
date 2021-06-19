using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SdandartDelegate
{
    class Program
    {
        static void Main(string[] args)
        {
            Action a0 = () => Console.WriteLine("Demo action");
            a0 += Message;
            a0();
            Action<int, double> a1 = (int a, double b) => Console.WriteLine($"{a} + {b} = {a + b}");
            a1(12, 4.5);
            Action<string, double> a2 = (str, num) => Console.WriteLine($"{str} > {num} symbols = {str.Length > num}");
            a2("Demo line", 5);

            Func<double, double, double> func = (a, b) => (a / b);
            double a = 10, b = 2.3;
            Console.WriteLine($"\nfunc({a}, {b}) = {func(a, b):F2}");

            Predicate<int> predEven = (x) => x % 2 == 0;
            int number = new Random().Next(1000);
            Console.WriteLine($"\nNumber {number} even : {predEven(number)}");

            Comparison<double> cmp = (a, b) => Math.Abs(a).CompareTo(Math.Abs(b));
            Console.WriteLine($"Compare by absolute values");




        }

        static void Message()
        {

            Console.WriteLine("Hello Std action!");
        }
    }
}
