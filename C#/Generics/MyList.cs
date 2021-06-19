using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics
{


    class MyList<T> : IMyList<T>, IMyCollection<T>, IEnumerable<T>
    {
        T[] arr;
        public int Сapacity { get; set; }
        int count = 0;
        const int defaultCapacity = 10;
        public MyList(int capacity = defaultCapacity) 
        {
            if (Сapacity <= 0)
                Сapacity = defaultCapacity;
            arr = new T[capacity];
        }
        public int Count => count;
        public bool IsEmpty => count == 0;
        private void CheckIndex(int index)
        {
            if ((index < 0) || (index >= count))
                throw new IndexOutOfRangeException("Incorrect index!");
        }
        public T this[int index]
        {
            get
            {
                CheckIndex(index);
                return arr[index];
            }
            set
            {
                CheckIndex(index);
                arr[index] = value;
            }
            
        }
        public void Clear()
        {
            count = 0;
        }
        public bool Contains(T item)
        {
            foreach (T element in arr)
            {
                if (element.Equals(item))
                    return true;
            }
            return false;
        }
        public int IndexOf(T item)
        {
            int i = 0;
            while ((i < count) && (!arr[i].Equals(item)))
            {
                i++;
            }
            if (i == count)
            {
                return -1;
            }
            return i;
        }
        public int LastIndexOf(T item)
        {
            int i = 0, j = 0;
            while ((i < count))
            {
                if ((!arr[i].Equals(item)))
                {
                    j++;
                }
                i++;
            }
            if (i == count)
            {
                return -1;
            }
            return j;
        }
        private void TryResize()
        {
            count++;
            if (Сapacity < Count)
            {
                Array.Resize(ref arr, Сapacity == 0 ? 1 : Сapacity * 2);
            }
        }
        public void Insert(int index, T item)
        {
            if ((index < 0) || (index > count))
                throw new IndexOutOfRangeException("Incorrect index!");
            TryResize();
            for (var i = count - 1; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = item;
        }
        public void RemoveAt(int index)
        {
            CheckIndex(index);
            for (var i = index; i < count - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[count - 1] = default(T);
            count--;
        }
        public bool Remove(T item)
        {
            if (IndexOf(item) == -1)
                return false;
            RemoveAt(IndexOf(item));
            return true;
        }
        public void Add(T item)
        {
            Insert(count, item);
        }
        public List<T> FindAll(Predicate<T> match)
        {
            List<T> result = new();
            int i = 0;
            while (i < count)
            {
                if (match(arr[i]))
                {
                    result.Add(arr[i]);
                }
                ++i;
            }
            return result;
        }
        public T Find(Predicate<T> match)
        {
            int i = 0;
            while ((i < count) && (!match(arr[i])))
            {
                i++;
            }
            if (i == count)
            {
                return default(T);
            }
            return arr[i];
        }
        public IEnumerator<T> GetEnumerator()
        {

            foreach (var item in arr)
            {
                yield return item;
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return arr.GetEnumerator();
        }
    }
}
