using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes 
{
    public class Rectangle : Shape
    {
        const uint MinHeight = 2;
        const uint MinLength = 2;
        public uint height;
        public uint length;
        public bool is_rec = true;
        public Rectangle(Position pos, ConsoleColor col, uint height = 2, uint length = 2)
            : base(pos, col)
        {
            Height = height;
            Length = length;
            FinishPoint = finishPoint;

        }
        
        public uint Height
        {
            get => height;
            set => height = value > 1 ? value : MinHeight;
        }
        public uint Length
        {
            get => length;
            set => length = value > 1 ? value : MinLength;
        }
        public override uint Area => height* length;
        public override uint Perimetr => 2 * (height + length);
        public override void Draw()
        {
            
            Console.CursorTop = basePoint.Y;
            Console.ForegroundColor = color;
            for (int i = 0; i < height; i++)
            {
                Console.CursorLeft = basePoint.X;
                for (int j = 0; j < length; j++)
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
                finishPoint.X = basePoint.X + (int)Length - 1;
                finishPoint.Y = basePoint.Y + (int)Height - 1;
            }
        }
        public override string ToString()
        {
            return $"Shape name : {this.GetType().Name}\t\tBase point : X:{basePoint.X}, Y:{basePoint.Y}\t\tColor : {color}\t\tHeight : {Height}\t\tLength : {Length}\t\tArea : {Area}\tLength : {Perimetr}";
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
        // Не переписував Equals для Rectangle, оскільки є поле finishPoint, де враховані поля height і length
        public void Deconstruct(out Position position, out ConsoleColor color, out uint height, out uint length, out uint area, out uint perimetr)
        {
            position = base.basePoint;
            color = base.color;
            height = Height;
            length = Length;
            area = Area;
            perimetr = Perimetr;
        }
    }
}
