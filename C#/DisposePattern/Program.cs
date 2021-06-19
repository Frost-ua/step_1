using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DisposePattern
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileWorker demo = new FileWorker("Demo text.txt"))
            {
                demo.Open();
                Console.WriteLine("Do some work...");
                Console.WriteLine($"List<> capacity : {demo.buffer.Count}");
            }
            Console.WriteLine("==================================");
            FileWorker demo2 = new FileWorker("Demo text.txt");
            Console.WriteLine("Do some work...");
            demo2.Dispose();
        }
    }
}
