using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shapes;

namespace UseCanvas
{
    static class StringExt
    {
        public static string DeleteVovels(this string str)
        {
            const string vovels = "AEIOYUaeioyu";
            int index = str.IndexOfAny(vovels.ToCharArray());
            while (index != -1)
            {
                str = str.Remove(index, 1);
                index = str.IndexOfAny(vovels.ToCharArray(), index + 1);
            }
            return str; 
        }
    }

    static class intExt
    {
        public static int SumDigits(this int num)
        {
            num = Math.Abs(num);
            int sum = 0;
            while (num != 0)
            {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Point a = new Point(new Position(1, 1), ConsoleColor.Blue);
            Rectangle b = new Rectangle(new Position(2, 2), ConsoleColor.Red, 5, 15);
            Rectangle f = new Rectangle(new Position(30, 3), ConsoleColor.Green, 5, 25);
            Square c = new Square(new Position(20, 6), ConsoleColor.Yellow, 5);

            Canvas d = new Canvas(15, 60);
            d.DrawCanvas();
            d.AddShapeToCanvas(a);
            d.AddShapeToCanvas(b);
            d.AddShapeToCanvas(c);
            d.AddShapeToCanvas(f);
            d.DrawAllShapes();

            List<Shape> shape_list = new();
            shape_list.Add(a);
            shape_list.Add(b);
            shape_list.Add(c);
            shape_list.Add(f);
            foreach (Shape s in shape_list)
                s.Print();

            Console.WriteLine("\n\nAfter sorting shapes by area :\n");
            shape_list.Sort((s1, s2) => s1.Area.CompareTo(s2.Area));
            foreach (Shape s in shape_list)
                s.Print();

            List<Shape> rectangle_list = shape_list.FindAll(x => (x.GetType().Name == "Rectangle"));
            Console.WriteLine("\nRectangle list :\n");
            foreach (Shape s in rectangle_list)
                s.Print();

            Console.ReadKey();
            d.ClearCanvas();
            Console.WriteLine("\nThe canvas after clearing");
            Console.ReadKey();
            Console.Clear();
            Console.WriteLine("====================TASK #2 (Extension methods) ==================\n");
            Console.WriteLine($"Sum of digits : {intExt.SumDigits(-5485)}");
            Console.WriteLine($"String after deleting all vovels : \t{StringExt.DeleteVovels("The following example finds the first vowel in a string.")}");


        }
    }
}
