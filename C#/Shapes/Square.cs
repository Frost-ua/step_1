using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    public class Square : Shape
    {
        const uint MinSide = 2;
        public uint side;
        public Square(Position pos, ConsoleColor col, uint side = 2)
            : base(pos, col)
        {
            Side = side;
            FinishPoint = finishPoint;
        }
        public uint Side
        {
            get => side;
            set => side = value > 1 ? value : MinSide;
        }
        public override uint Area => Side * Side;
        public override uint Perimetr => 4 * Side;
        public override void Draw()
        {
            Console.CursorTop = basePoint.Y;
            Console.ForegroundColor = color;
            for (int i = 0; i < Side; i++)
            {
                Console.CursorLeft = basePoint.X;
                for (int j = 0; j < Side; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            Console.ResetColor();
        }
        public new Position FinishPoint
        {
            get => finishPoint;
            set
            {
                finishPoint.X = basePoint.X + (int)Side - 1;
                finishPoint.Y = basePoint.Y + (int)Side - 1;
            }
        }
    }
}
