using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEvents
{
    class Cooler
    {
        const int Shift = 5;
        public void Cool(HotHouse house)
        {
            Console.WriteLine($"The cooler decreased temperature by {Shift} C.");
            house.Temperature -= 5;
            

        }
    }
}
