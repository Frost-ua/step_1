/*
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace My_Queue
{
    class EmptyQueeueException
    { 
    
    }

    class MyQueue<T> : IMyQueue <T>
    {
        const int defaultCapacity = 10;
        T[] arr;
        int capacity;
        int realSize = 0;

        public MyQueue(int capacity = defaultCapacity)
        {
            if (capacity <= 0)
            {
                this.capacity = defaultCapacity;
            }
            else
            {
                this.capacity = capacity;
            }
            arr = new T[capacity]; //[][][][][]

        }

        public bool IsEmpty => realSize == 0;
        public bool IsFull => realSize == capacity;
        public void Clear()
        {
            realSize = 0;
        }

        public T Dequeue(T elememt)
        {
            if (IsEmpty)
            {
                throw new EmptyQueeueException();
            }
            T tmp = arr[0];
            Array.Copy(arr, 1,)
        }

        public T Enqueue(T elememt)
        {
            if (IsFull)
            {
                capacity *= 2;
                Array.Resize(ref arr, capacity); // increase size and copy old elements
                arr[realSize] = elememt;
                ++realSize;
            }
        }

        public T Peek()
        {
            if (IsEmpty)
            {
                throw new EmptyQueeueException();
            }
        }
    }

}
*/
