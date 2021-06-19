using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEventHandler
{
    public class Animal
    {
        public event EventHandler Feed;
        public static uint FullEnergy = 50;
        public bool Is_hungry = false;
        const uint MinEnergy = 10, LossEnergySmallAnimal = 5, LossEnergyMiddleAnimal = 7, LossEnergyBigAnimal = 21;
        public string Name { get; set; }
        public uint Weight { get; set; }
        uint energy;

        public Animal(string name = "Noname", uint weight = 1)
        {
            this.Name = name;
            this.Weight = weight;
            this.energy = FullEnergy;
        }
        public uint Energy
        {
            get => energy;
            set
            {
                if (Is_hungry)
                    Feed?.Invoke(this, EventArgs.Empty);
                else
                    energy = value;
            }
        }
        public void Run()
        {
            uint rounds = 10;
            Console.WriteLine($"\n=======   {Name} run! ========");
            for (int i = 0; i < rounds; i++)
            {
                Console.WriteLine($"Round {i + 1} \t\tEnergy : {Energy}");
                if (Weight > 0 && Weight <= 5)
                {
                    CheckEnergy(ref i);
                    Energy -= LossEnergySmallAnimal;
                }
                else if (Weight > 5 && Weight <= 30)
                {
                    CheckEnergy(ref i);
                    Energy -= LossEnergyMiddleAnimal;
                }
                else if (Weight > 30)
                {
                    CheckEnergy(ref i);
                    Energy -= LossEnergyBigAnimal;
                }
                if (this.Feed == null && Energy <= MinEnergy)
                {
                    Console.WriteLine($"Round {i + 2}\n---===   {Name} has too low energy : {Energy} !!!\tNo one feeds this animal!");
                    break;
                }
            }
        }
        void CheckEnergy(ref int counter)
        {
            if (Energy <= MinEnergy)
            {
                --counter;
                Is_hungry = true;
            }
        }
    }
}
