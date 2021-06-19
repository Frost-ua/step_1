using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericDelegate
{
    delegate T AddDelegate<T>(T one, T two);  // create delegate, type
    delegate double CalcDelegate(double a, double b);

    class Program
    {
        static void Main(string[] args)
        {
            AddDelegate<double> d1 = AddCalculator.AddNumbers;
            double num1 = 1.2, num2 = 3.4;
            Console.WriteLine($"{num1} + {num2} = {d1(num1, num2)}");

            AddDelegate<string> d2 = AddCalculator.ConcatString;
            string word1 = "One", word2 = "Two";
            Console.WriteLine($"{word1} + {word2} = {d2(word1, word2)}");

            AddDelegate<TimeSpan> d3 = AddCalculator.AddTimeSpan;
            TimeSpan t1 = new TimeSpan(10, 12, 45), t2 = new TimeSpan(2, 47, 15);
            Console.WriteLine($"{t1} + {t2} = {d3(t1, t2)}");


        }
    }

  

    class AddCalculator
    {
        public static double AddNumbers(double a, double b) => a + b;
        public static string ConcatString(string a, string b) => a + " " + b;
        public static TimeSpan AddTimeSpan(TimeSpan a, TimeSpan b) => a + b;


    }

}
