using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEvents
{
    class Heater
    {
        const int Shift = 5;
        public void Warm(HotHouse house)
        {
            Console.WriteLine($"The heater increased temperature by {Shift} C.");
            house.Temperature += Shift;
            
        }
    }
}
