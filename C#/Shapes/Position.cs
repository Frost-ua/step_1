using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
   public class Position
    {
        public int x;
        public int y;

        public Position(int x = 0, int y = 0)
        {
            X = x;
            Y = y;
        }
        public int X
        {
            get => x;
            set => x = value > 0 ? x = value : x = 0;
        }
        public int Y
        {
            get => y;
            set => y = value > 0 ? y = value : y = 0;
        }
        public override string ToString()
        {
            return $"X : {X}\t Y : {Y}";
        }
        public override bool Equals(object obj)
        {
            Position p = obj as Position;
            if (p is null)
            {
                return false;
            }
            return X == p.X && Y == p.Y;
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
        public void Deconstruct(out int x, out int y)
        {
            x = X;
            y = Y;
        }
    }
}
