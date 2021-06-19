using Interfaces;
using System;

namespace Delegates
{
    delegate void MyDelegate(uint height, ConsoleColor color);
    class Program
    {
        static char[,] CreateFullMatrix(uint height)
        {
            char[,] matrix = new char[height, height];
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    matrix[i, j] = '*';
                }
            }
            return matrix;
        }
        static void DrawSquare(uint height, ConsoleColor color)
        {
            char[,] result = CreateFullMatrix(height);
            Console.ForegroundColor = color;
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    Console.Write($"{ result[i, j]} ");
                }
                Console.WriteLine();
            }
            Console.ResetColor();
            Console.WriteLine();
        }
        static void DrawTriangle(uint height, ConsoleColor color)
        {
            char[,] result = CreateFullMatrix(height);
            Console.ForegroundColor = color;
            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j <= i; ++j)
                {
                    Console.Write($"{ result[i, j]} ");
                }
                Console.WriteLine();
            }
            Console.ResetColor();
            Console.WriteLine();
        }
        static void BubbleSort<T>(T[] arr, Comparison<T> comp)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (comp(arr[j], arr[i]) < 0)
                    {
                        var temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        static void InsertSort<T>(T[] arr, Comparison<T> comp)
        {
            for (int i = 1; i < arr.Length; i++)
		    {
                int j = i - 1;
                T Temp = arr[i];
			    while (j >= 0 && comp(arr[j], Temp) > 0)
			    {
				    arr[j + 1] = arr[j];
				    arr[j] = Temp;
				    j--;
			    }
		    }
        }
        static int CompareWordsByLength(string x, string y)
        {
            if (x == null)
            {
                if (y == null)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (y == null)
                {
                    return 1;
                }
                else
                {
                    int retval = x.Length.CompareTo(y.Length);
                    if (retval != 0)
                    {
                        return retval;
                    }
                    else
                    {
                        return x.CompareTo(y);
                    }
                }
            }
        }
        static void PrintArr<T>(T[] arr)
        {
            foreach (var el in arr)
            {
                Console.WriteLine(el);
            }
        }



            static void Main(string[] args)
        {
            Console.WriteLine("##############################   TASK #1   ###################################\n");

             MyDelegate deleg = new MyDelegate(Program.DrawSquare);        // or  MyDelegate deleg = DrawSquare;
             //DrawSquare(10, ConsoleColor.Green);                         // explicit method call
             deleg.Invoke(10, ConsoleColor.Green);                         // implicit method call using delegate
             deleg = DrawTriangle;
             deleg.Invoke(10, ConsoleColor.Yellow);
             deleg += DrawSquare;                                          // multicast delegate
             deleg.Invoke(5, ConsoleColor.Blue);                           // Draws both shapes  

            Console.WriteLine("##############################   TASK #2   ###################################\n");

            Calculator calc = new Calculator();
            double a = 25.4, b = 3.7;
            try
            {
                //Console.WriteLine($"{a} + {b} = {calc.Calculate(a, b):F2}");

                calc.SetOperation(Calculator.Operation.Addition);
                Console.WriteLine($"{a} + {b} = {calc.Calculate(a, b):F2}");
                calc.SetOperation(Calculator.Operation.Subtraction);
                Console.WriteLine($"{a} - {b} = {calc.Calculate(a, b):F2}");
                calc.SetOperation(Calculator.Operation.Multiplication);
                Console.WriteLine($"{a} * {b} = {calc.Calculate(a, b):F2}");
                calc.SetOperation(Calculator.Operation.Division);
                Console.WriteLine($"{a} / {b} = {calc.Calculate(a, b):F2}");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("\n##############################   TASK #3   ###################################\n\n==========   Before sorting   ===========================");
            string[] words = { "Apple", "Orange", "Pineapple", "Banana", "Avocado", "Blueberry", "Blackberry", "Lime" };
            PrintArr(words);
            Console.WriteLine("\n==========   After sorting by Bubble method   ===========================");
            BubbleSort(words, CompareWordsByLength /* OR Lambda (x, y) => x.Length.CompareTo(y.Length)*/);
            PrintArr(words);
            Console.WriteLine("\n==========   After sorting by Insertion method by decrease   ===========================");
            InsertSort(words, (x, y) => -x.Length.CompareTo(y.Length));
            PrintArr(words);

            Employee[] emArr =
            {
                new Employee("Jordy", "Frost", "Feature developer", 7000, "FF56-2567"),
                new Employee("Alex", "Frost", "QA Lead", 5500, "GTUY-2362"),
                new Employee("Kate", "Black", "3D Artist", 5800, "FOUJ-12K8"),
                new Employee("Ann", "Palmer", "Feature developer", 6200, "YUIO-UDTT"),
                new Employee("John", "Anderson", "Animator", 5900, "FU36-2689")
            };

            Console.WriteLine("\n==========   Before sorting Emloyees   ===========================");
            PrintArr(emArr);
            Console.WriteLine("\n==========   After sorting Emloyees by salary by increase   ===========================");
            BubbleSort(emArr, (x, y) => x.Salary.CompareTo(y.Salary));
            PrintArr(emArr);

        }
        class Calculator {

            public enum Operation { Addition, Subtraction, Multiplication, Division };
            public Func<double, double, double> func;
            public void SetOperation(Operation operation)
            {
                if (operation == Operation.Addition)
                {
                    func = (a, b) => a + b;
                }
                else if (operation == Operation.Subtraction)
                {
                    func = (a, b) => a - b;
                }
                else if (operation == Operation.Multiplication)
                {
                    func = (a, b) => a * b;
                }
                else if (operation == Operation.Division)
                {
                    func = Division;
                }

            }
            public double Calculate(double a, double b)
            {
                if (func != null)
                    return func.Invoke(a, b);
                else
                    throw new Exception("Delegate 'func' == null");
            }
            private double Division(double a, double b)
            {
                if (b != 0)
                    return a / b;
                else
                    throw new DivideByZeroException("Division by zero!");
            }
        }
    }
}

