using System;

namespace MyEventHandler
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal dog = new Animal("Dog", 7);
            Human ann = new Human("Ann");
            dog.Feed += ann.FeedAnimal;
            dog.Run();

            Animal pig = new Animal("Pig", 120);
            pig.Feed += ann.FeedAnimal;
            pig.Run();

            Animal bull = new Animal("Bull", 500);
            bull.Run();
        }
    }
}
