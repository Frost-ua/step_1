using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    public abstract class Shape
    {
        public Position basePoint = new();
        public Position finishPoint = new();
        public bool Into_Canvas {get; set;}
        public ConsoleColor color = ConsoleColor.DarkRed;
        public abstract uint Area { get; }
        public abstract uint Perimetr { get; }

        public Shape(Position pos, ConsoleColor col)
        {
            basePoint = pos;
            color = col;

        }
        public virtual void Print()
        {
            /*if (Into_Canvas)
            {*/
                Console.WriteLine($"Shape name : {this.GetType().Name}\t\tBase point : X:{basePoint.X}, Y:{basePoint.Y}\t\tColor : {color}\t\tArea : {Area}\tLength : {Perimetr}");
            /*}*/
            
        }

        public abstract void Draw();
        public virtual Position FinishPoint
        {
            get => finishPoint;
        }

        public override string ToString()
        {
            return $"Shape name : {this.GetType().Name}\t\tBase point : X:{basePoint.X}, Y:{basePoint.Y}\t\tColor : {color}\t\tArea : {Area}\tLength : {Perimetr}";
        }
        public override bool Equals(object obj)
        {
            Shape p = obj as Shape;
            if (p is null)
            {
                return false;
            }
            return basePoint.Equals(p.basePoint) && finishPoint.Equals(p.finishPoint) && color == p.color && Area == p.Area && Perimetr == p.Perimetr;
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }
}
