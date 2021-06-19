using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEvents
{
    delegate void HotHouseDeleg(HotHouse house);
    class HotHouse
    {
        int temperature;
        const int MinTem = 15;
        const int MaxTem = 25;
        public HotHouse(int temperature)
        {
            this.Temperature = temperature;
        }

        public event HotHouseDeleg TooHot;
        public event HotHouseDeleg TooCold;
        public event Action Well;

        public int Temperature
        {
            get => temperature;
            set
            {
                temperature = value;
                if (temperature <= MinTem)
                {
                    if (temperature < MinTem)
                        temperature = MinTem;
                    Console.WriteLine("Too cold.");
                    TooCold?.Invoke(this);
                }
                else if (temperature >= MaxTem)
                {
                    if (temperature > MaxTem)
                        temperature = MaxTem;
                    TooHot?.Invoke(this);
                }
                else
                    Well?.Invoke();

            }
        }
        public void NormalTemperature()
        {
            Console.WriteLine($"The temperature in HotHouse is within normal limits : {Temperature} C");
        }
    }
}
