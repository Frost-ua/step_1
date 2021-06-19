using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shapes;

namespace Equals
{
    class Program
    {
        static (uint, string, Shape) getResult(List<object> list)         // Method, which returns tuple
        {
            List<int> digit_list = new();
            List<string> string_list = new();
            List<Shape> shape_list = new();
            for (int i = 0; i < list.Count; i++)
            {
                if (list[i] is uint || list[i] is int)
                    digit_list.Add((int)list[i]);
                if (list[i] is string)
                    string_list.Add((string)list[i]);
                if (list[i] is Shape)
                    shape_list.Add((Shape)list[i]);
            }
           /* var max_digit = digit_list.Max();                                                                     // The biggest digit
            var longest_str = string_list.Where(s => s.Length == string_list.Max(m => m.Length)).First();           // The longest string
            var max_shape_area = shape_list.Where(s => s.Area == shape_list.Max(m => m.Area)).First();*/            // The biggest shape by area

            return (
                (uint)digit_list.Max(),
                string_list.Where(s => s.Length == string_list.Max(m => m.Length)).First(),
                shape_list.Where(s => s.Area == shape_list.Max(m => m.Area)).First()
                );
        }

        static void Main(string[] args)
        {
            Position a = new Position(5, 6);
            Position b = new Position(5, 5);
            Console.WriteLine($"==================   {a.GetType().Name}   =======================");
            Console.WriteLine($"Equals positions a, b : {Equals(a, b)}");
            Console.WriteLine($"Hash of positions : a  {a.GetHashCode()}\tb  {b.GetHashCode()}");

            Point c = new Point(a, ConsoleColor.Red);
            Point d = new Point(a, ConsoleColor.Red);
            Console.WriteLine($"\n==================   {c.GetType().Name}   =======================");
            Console.WriteLine($"Equals points c, d : {Equals(c, d)}");
            Console.WriteLine($"Hash of points : c  {c.GetHashCode()}\td  {d.GetHashCode()}");

            Rectangle n = new Rectangle(b, ConsoleColor.Yellow, 5, 10);
            Rectangle m = new Rectangle(b, ConsoleColor.Yellow, 10, 5);
            Console.WriteLine($"\n==================   {n.GetType().Name}   =======================");
            Console.WriteLine($"Equals rectangles n, m : {Equals(n, m)}");
            Console.WriteLine($"Hash of rectangles : n  {n.GetHashCode()}\tm  {m.GetHashCode()}");

            Square k = new Square(new Position(4, 3), ConsoleColor.Blue, 6);
            Square l = new Square(new Position(1, 1), ConsoleColor.Yellow, 8);


            List<object> list = new List<object> {1, 15, 45, "simplest", "way", "to", "get", "started", "with", "HOPR", c, d, n, m, k, l };
            ValueTuple<uint, string, Shape> result = getResult(list);
            Console.WriteLine($"\n========   Method, which returns tuple   ============\nThe biggest positive array number : {result.Item1}\nThe longest string : {result.Item2}\nThe largest shape by area : \n{result.Item3}");

            Console.WriteLine("\n======================   Deconstruct   ===================\n");
            Position pos = new Position(10, 15);
            var (x, y) = pos;
            Console.WriteLine($"Position : X {x}, Y {y}");
            Point point = new Point(pos, ConsoleColor.Green);
            var (base_position, color) = point;
            Console.WriteLine($"Point : base position : {base_position}\tcolor\t{color}");
            Rectangle rec = new Rectangle(pos, ConsoleColor.Yellow, 50, 120);
            var (rec_base_position, rec_color, height, length, rec_area, rec_perimetr) = rec;
            Console.WriteLine($"Rectangle : base position : {rec_base_position}\tcolor : {rec_color}\theight : {height}\tlength : {length}\tarea : {rec_area}\tperimetr : {rec_perimetr}");
        }
    }
}
