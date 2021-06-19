using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEvents
{
   class Weather
    {
        const int Shift = 2, MaxWeatherTem = 40, MinWeatherTem = -20;
        int сurrent_temperature;
        public Weather()
        {
            this.CurrentTemperature = new Random().Next(18, 22); ;
        }
        public int CurrentTemperature
        {
            get => сurrent_temperature;
            set
            {
                сurrent_temperature = value;
                if (сurrent_temperature > MaxWeatherTem)
                    сurrent_temperature = MaxWeatherTem;
                if (сurrent_temperature < MinWeatherTem)
                    сurrent_temperature = MinWeatherTem;
            }
        }
        public void WarmsUp()
        {
            CurrentTemperature += Shift;
            Console.WriteLine($"Outside temperature : {CurrentTemperature} C.");
        }
        public void GetColder()
        {
            CurrentTemperature -= Shift;
            Console.WriteLine($"Outside temperature : {CurrentTemperature} C.");

        }
        public int GetRandonWeather()
        {
            int rdn = new Random().Next(0,2);
            if (rdn == 1)
            {
                WarmsUp();
                return CurrentTemperature;
            }
            else
            {
                GetColder();
                return CurrentTemperature;
            }
        }

    }
}
