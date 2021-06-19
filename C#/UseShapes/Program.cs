using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shapes;

namespace UseShapes
{
    class Program
    {
        static void Main(string[] args)
        {
            Point a = new Point(new Position(1, 1), ConsoleColor.Blue);
            Rectangle b = new Rectangle(new Position(2, 2), ConsoleColor.Red, 5, 15);
            Rectangle f = new Rectangle(new Position(30, 3), ConsoleColor.Green, 5, 25);
            Square c = new Square(new Position(20, 6), ConsoleColor.Yellow, 5);
            
            List <Shape> shape_list = new();
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
            
            List<Shape> rectangle_list = shape_list.FindAll(x => (x.GetType().Name == "Rectangle")) ;
            Console.WriteLine("\nRectangle list :\n");
            foreach (Shape s in rectangle_list)
                s.Print();

        }
    }
}
