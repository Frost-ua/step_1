using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    public class Canvas
    {
        public List<Shape> shape_list = new();
        public uint canvas_width;
        public uint canvas_length;
        const uint MAX_WIDTH = 31, MIN_WIDTH = 11, MAX_LENGTH = 101, MIN_LENGTH = 51;
        public Canvas(uint canvas_width = MIN_WIDTH, uint canvas_lenhth = MIN_LENGTH)
        {
            Canvas_Width = canvas_width;
            Canvas_Length = canvas_lenhth;
        }
        public uint Canvas_Width
        {
            get => canvas_width;
            set => canvas_width = value > 0 || value < MAX_WIDTH ? value : MIN_WIDTH;
        }
        public uint Canvas_Length
        {
            get => canvas_length;
            set => canvas_length = value > 0 || value < MAX_LENGTH ? value : MIN_LENGTH;
        }

        public void DrawCanvas()
        {
            for (int i = 0; i < Canvas_Width; i++)
            {
                for (int j = 0; j < Canvas_Length; j++)
                {
                    if (i == 0 || i == Canvas_Width - 1)
                    {
                        Console.Write("*");
                    }
                    else if (j == 0 || j == Canvas_Length - 1)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
               
            }
        }
        public void AddShapeToCanvas(Shape obj)
        {
            shape_list.Add(obj);
        }
        public void ClearCanvas()
        {
            shape_list.Clear();
            Console.Clear();
            DrawCanvas();

        }
        public void DrawAllShapes()
        {
            for (int i = 0; i < shape_list.Count; i++)
            {

                
                if (shape_list[i].basePoint.X > 0 && shape_list[i].basePoint.Y < Canvas_Width - 1 && shape_list[i].FinishPoint.X < Canvas_Length - 1 && shape_list[i].FinishPoint.Y < Canvas_Width - 1)
                {
                    shape_list[i].Draw();
                    shape_list[i].Into_Canvas = true;
                }

                Console.WriteLine("\n\n\n\n\n\n");
            }
        }
    }
}
