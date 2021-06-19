using System;

namespace MyEvents
{
    class Program
    {
       

        static void Main(string[] args)
        {
            Weather w = new Weather();
            HotHouse house = new HotHouse(w.CurrentTemperature);
            Heater h = new Heater();
            Cooler c = new Cooler();
            house.TooCold += h.Warm;
            house.TooHot += c.Cool;
            house.Well += house.NormalTemperature;

            while (true)
            {
                house.Temperature = w.GetRandonWeather();
                Console.ReadKey();
            }
            
        
        }
    }
}
