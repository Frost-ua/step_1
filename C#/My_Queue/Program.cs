using System;
using System.Collections.Generic;

namespace My_Queue
{
    class Program
    {
        interface IMyQueue<T> 
        {
            void Enqueue(T element);
            T Dequeuue(T element);
            T Peek();

            bool IsEmpty { get; }
            void Clear();



             
        }








        static void Main(string[] args)
        {
            
        }
    }
}
