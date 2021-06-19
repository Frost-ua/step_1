using Interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace MyFileStream
{
    class Program
    {
        static void Main(string[] args)
        {
            string str_code, str_keywords;
            string fname = "../../../MyList_TEST.cs", fname_keywords = "../../../KeyWords.txt";
            using (StreamReader sr = new StreamReader(fname))
            {
                str_code = sr.ReadToEnd();                                // read all code from file to string
            }
            using (StreamReader sr = new StreamReader(fname_keywords))
            {
                str_keywords = sr.ReadToEnd();                             // read keywords from file to string
            }

            string[] words_from_code = str_code.Split("\n\r ,[]{}();*\"<>:=+.-!'0123456789|".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);  // convert a string to an array of strings with each word apart
            string[] for_print = str_code.Split(" ");                                                               // convert code to an array of strings with each word/symbol apart
            string[] str_tmp = str_keywords.Split(" \n\r".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);    // convert all keywords to an array of strings with each word apart
            HashSet<string> keywords = new HashSet<string>(str_tmp);                                     // Copy an array of keywords to HashSet<>

            Console.WriteLine("=================================   TASK #1   ======================================");

            for (int i = 0; i < for_print.Length; i++)                   // Print all code from file
            {
                if (keywords.Contains(for_print[i]))
                {
                    Console.ForegroundColor = ConsoleColor.Green;        // If there is a keyword, the word is highlighted
                    Console.Write(for_print[i] + " ");
                    Console.ResetColor();
                }
                else
                {
                    Console.Write(for_print[i] + " ");
                }
            }

            Dictionary<string, int> result = new();                   // Create Dictionary<keyword, keyword's count>
            string tmp;
            int count = 0;
            for (int i = 0; i < keywords.Count; i++)
            {
                count = 0;
                tmp = keywords.ElementAt(i);
                for (int j = 0; j < words_from_code.Length; j++)              // Search keywords and their count
                {
                    if (tmp == words_from_code[j])
                    {
                        ++count;
                    }
                }
                if (!result.ContainsKey(keywords.ElementAt(i)) && count > 0)
                    result.Add(keywords.ElementAt(i), count);
            }
            int num = 1;
            Console.WriteLine("#\t\tWord :\t\tCount : \n--------------------------------------------------");
            foreach (var w in result)
            {
                Console.WriteLine($"{num}.\t\t{w.Key,-20}{w.Value}");         
                ++num;
            }

            Console.WriteLine("\n=================================   TASK #2   ======================================");
            Employee jordy = new Employee("Jordy", "Frost", "Feature developer", 7000, "FF56-2567");
            Employee alex = new Employee("Alex", "Frost", "QA Lead", 5500, "GTUY-2362");
            Employee kate = new Employee("Kate", "Black", "3D Artist", 5800, "FOUJ-12K8");
            Employee ann = new Employee("Ann", "Palmer", "Feature developer", 6200, "YUIO-UDTT");
            Employee john = new Employee("John", "Anderson", "Animator", 5900, "FU36-2689");

            List<Employee> em_list = new List<Employee> { jordy, alex, kate, ann, john};                        // Create List of Employees
            Console.WriteLine("\n===========================   Before saving List<Employee>   =================================\n");
            foreach (var em in em_list)
            {
                Console.WriteLine(em);                                                                            // Print List
            }
            Console.WriteLine("\n===========================   After loading from file List<Employee>   =================================\n");

            string fname1 = "../../../Employees.dat";
            FileWorker.SaveEmployee(em_list, fname1);                                                       // Save List to the file

            List<Employee> read_em_list = FileWorker.LoadEmployee(fname1);                                  // Read List of Employees from file
            foreach (var em in read_em_list)
            {
                Console.WriteLine(em);                                                                          // Print List
            }



        }
    }
}
