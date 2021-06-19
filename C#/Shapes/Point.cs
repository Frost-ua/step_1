using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    public class Point : Shape
    {
        public Point(Position pos, ConsoleColor col)
            : base(pos, col)
        { 
        }

        public sealed override uint Area => 0;
        public sealed override uint Perimetr => 0;
        public override void Draw()
        {
            /*Console.CursorTop = basePoint.Y;
            Console.CursorLeft = basePoint.X;*/
            Console.SetCursorPosition(basePoint.X, basePoint.Y);
            Console.ForegroundColor = color;
            Console.WriteLine("*");
            Console.ResetColor();
        }
        public void Deconstruct(out Position position, out ConsoleColor color)
        {
            position = base.basePoint;
            color = base.color;
        }

    }
}
