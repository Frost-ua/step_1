using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyEventHandler
{
    class Human
    {
        public string Name { get; set; }
        public Human(string name = "No name")
        {
            Name = name;
        }
        public void FeedAnimal(object sender, EventArgs e)
        {
            Animal animal = sender as Animal;
            if (animal != null)
            {
                animal.Is_hungry = false;
                animal.Energy = Animal.FullEnergy;
                Console.WriteLine($"---===   {Name} feeds the {animal.Name}. Energy {animal.Energy}.");
            }        
        }
    }
}
