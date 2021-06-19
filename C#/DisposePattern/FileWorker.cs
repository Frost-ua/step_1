using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DisposePattern
{
    class FileWorker : IDisposable
    {
        enum Mode { Read, Write, ReadWrite };

        const int size = 100;
        static int lastId = 0;
        public readonly int ID = ++lastId;
        public List<int> buffer; 
        string name;
        private bool disposed = false, is_opened = false;   // Check object is deleted or not
        public FileWorker(string name = "NoName")
        {
            this.name = name;
            buffer = new List<int> { 10, 100, 15, -12, 1256 }; ;
            Console.WriteLine($"Created #{ID}");
        }
        ~FileWorker() 
        {
            Console.WriteLine("Finalizator!!!");
            CleanUp(false);
        }
        private void CleanUp(bool clean)
        {
            if (!this.disposed)
            {
                if (clean)
                {
                    Console.WriteLine("Clean managed resources.");
                    buffer.Clear();
                    Console.WriteLine($"List<> capacity : {buffer.Count}");
                }
                Console.WriteLine("Clean unmanaged resources.");
                if (is_opened)
                {
                    Close();
                }
            }
            this.disposed = true;
        }
        public void Read()
        {
            if (!disposed)
                Console.WriteLine("Reading from the file...");
            throw new ObjectDisposedException(this.GetType().Name);
        }
        public void Write()
        {
            if (!disposed)
                Console.WriteLine("Writing to the file...");
            throw new ObjectDisposedException(this.GetType().Name);
        }
        public void Open()
        {
            if (!disposed)
            {
                Console.WriteLine("File stream is opened.");
                is_opened = true;
            }
        }
        public void Close()
        {
            if (!disposed)
                Console.WriteLine("File stream is closed.");
        }
        public virtual void Dispose()
        {
            CleanUp(true);
            GC.SuppressFinalize(this);
        }
    }
}
