using Interfaces;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Xml.Serialization;
using System.Net;

namespace Serialization
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee jordy = new() { Name = "Jordy", SurName = "Frost", Position = "Feature developer", Salary = 7000, ContractNumber = "RTYE12ERF-25" };
            Employee alex = new() { Name = "Alex", SurName = "Frost", Position = "QA Lead", Salary = 5500, ContractNumber = "GTUY-2362" };
            Employee kate_black = new() { Name = "Kate", SurName = "Black", Position = "3D Artist", Salary = 5800, ContractNumber = "FOUJ-12K8" };
            Employee ann = new() { Name = "Ann", SurName = "Palmer", Position = "Feature developer", Salary = 6200, ContractNumber = "YUIO-UDTT" };
            Employee john = new() { Name = "John", SurName = "Anderson", Position = "Animator", Salary = 5900, ContractNumber = "FU36-2689" };
            Employee ivan = new() { Name = "Ivan", SurName = "Shulga", Position = "3D-Artist", Salary = 6900, ContractNumber = "UHFYU-OI" };
            Employee mary = new() { Name = "Mary", SurName = "Jane", Position = "Animator", Salary = 6000, ContractNumber = "FJUFII-12" };
            Employee kate_anderson = new() { Name = "Kate", SurName = "Anderson", Position = "Feature developer", Salary = 6750, ContractNumber = "FHHFFU-55" };

            Project Hidden_city = new Project();
            Hidden_city.AddEmployeeToProject(jordy);
            Hidden_city.AddEmployeeToProject(alex);
            Hidden_city.AddEmployeeToProject(kate_black);
            Hidden_city.AddEmployeeToProject(ann);
            Hidden_city.AddEmployeeToProject(john);
            Hidden_city.AddEmployeeToProject(ivan);
            Hidden_city.AddEmployeeToProject(mary);
            Hidden_city.AddEmployeeToProject(kate_anderson);
            Console.WriteLine("#########################################   Binary serialization\\deserialization   ########################################\n\n" +
                "===================================== Project before serialization ============================\n");
            Hidden_city.ShowTeam();

            BinaryFormatter bf = new BinaryFormatter();
            string fname = "Project.dat";
            using (FileStream fs = new FileStream(fname, FileMode.Create))
            {
                bf.Serialize(fs, Hidden_city);
                fs.Position = 0;
                Project readProject = (Project)bf.Deserialize(fs);

                Console.WriteLine("\n================================== Project after deserialization ============================\n");
                readProject.ShowTeam();
            }
            Console.WriteLine("#########################################   XML serialization\\deserialization   ########################################\n\n" +
                "===================================== Team after deserialization from xml file ============================\n");

            Team ab_games = new();
            ab_games.AddEmployeeToTeam(jordy);
            ab_games.AddEmployeeToTeam(alex);
            ab_games.AddEmployeeToTeam(kate_anderson);

            XmlSerializer xs = new XmlSerializer(typeof(Team));
            string fname2 = "Team.xml";
            using (StreamWriter sw = new StreamWriter(fname2))
            {
                xs.Serialize(sw, ab_games);
            }

            using (StreamReader sr = new StreamReader(fname2))
            {
                Team readTeam = (Team)xs.Deserialize(sr);
                readTeam.ShowTeam();
            }

            Console.WriteLine("#########################################   Json serialization\\deserialization   ########################################\n\n===================================== Project after deserialization from json file ============================\n");

            string json = JsonConvert.SerializeObject(Hidden_city);

            string fname1 = "Project.json";
            using (StreamWriter sw = new StreamWriter(fname1))
            {
                sw.WriteLine(json);
            }
            using (StreamReader sr = new StreamReader(fname1))
            {
                string readJson = sr.ReadToEnd();
                
                Project readPr = JsonConvert.DeserializeObject<Project>(readJson);
                readPr.ShowTeam();
            }

            Console.WriteLine("\n#########################################   Currency by PrivatBank   ########################################\n\n");
            WebClient wc = new WebClient();
            string json5 = wc.DownloadString("https://api.privatbank.ua/p24api/pubinfo?json&exchange&coursid=5");
            List<Currency> readCurrensyList = JsonConvert.DeserializeObject<List<Currency>>(json5);
            
            string getCurrency;
            while (true)
            {
                bool is_found = false;
                Console.WriteLine("Enter currency : ");
                getCurrency = Console.ReadLine();
                for (int i = 0; i < readCurrensyList.Count; i++)
                {
                    if (string.Compare(getCurrency, readCurrensyList[i].Ccy, true) == 0)
                    {
                        Console.WriteLine(readCurrensyList[i]);
                        is_found = true;
                        break;
                    }
                }
                if (!is_found)
                    Console.WriteLine("Currency not found!");
                else
                    break;
            }
            Console.ReadKey();
            Console.WriteLine("\nAll currency : \n");
            foreach (var item in readCurrensyList)
            {
                Console.WriteLine(item);
            }
        }
    }
}
