using Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections
{

    class Program
    {

        private static void DisplayLList(LinkedList<Employee> team, string test)
        {
            Console.WriteLine(test);
            foreach (var e in team)
            {
                Console.WriteLine(e);
            }
            Console.WriteLine();
        }

        static void DisplaySet(HashSet<Employee> collection)
        {
            
            foreach (var i in collection)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            Console.WriteLine($"###################################################   TASK #1   ########################################################\n\n");

            string str = "Here is the house that Jack built.\n" +
                "And this is wheat, which is stored in a dark cell in the house that Jack built.\n" +
                "And this is a cheerful tit bird that often steals wheat,\n" +
                "which is stored in a dark cell in the house that Jack built.\n\n";
            Console.WriteLine(str);
            string[] words = str.Split(" \n,.-!'".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);     // Convert the sentence to separate words
            for (int i = 0; i < words.Length; i++)
            {
                words[i] = words[i].ToLower();              // Convert all words to lowercase
            }
            Dictionary<string, int> result = new();
            string tmp;
            for (int i = 0; i < words.Length; i++)
            {
                int count = 0;
                tmp = words[i];
                for (int j = 0; j < words.Length; j++)
                {
                    if (tmp == words[j])
                        ++count;                                   // Counter of the same words
                }
                if (!result.ContainsKey(words[i]))
                    result.Add(words[i], count);                   // Add unique word to Dictionary<>
            }
            int num = 1;
            Console.WriteLine("#\t\tWord :\t\tCount : \n--------------------------------------------------");
            foreach (var w in result)
            {
                Console.WriteLine($"{num}.\t\t{w.Key, -20}{w.Value}");         // Print Dictionary<>
                ++num;
            }
            Console.WriteLine($"--------------------------------------------------\nTotal words : {words.Length}\tUnique words : {result.Count}\n\n###################################################   TASK #3   ########################################################\n");

            Employee jordy = new() { Name = "Jordy", SurName = "Frost", Position = "Feature developer", Salary = 7000, ContractNumber = "RTYE12ERF-25" };
            Employee alex = new() { Name = "Alex", SurName = "Frost", Position = "QA Lead", Salary = 5500, ContractNumber = "GTUY-2362" };
            Employee kate_black = new() { Name = "Kate", SurName = "Black", Position = "3D Artist", Salary = 5800, ContractNumber = "FOUJ-12K8" };
            Employee ann = new() { Name = "Ann", SurName = "Palmer", Position = "Feature developer", Salary = 6200, ContractNumber = "YUIO-UDTT" };
            Employee john = new() { Name = "John", SurName = "Anderson", Position = "Animator", Salary = 5900, ContractNumber = "FU36-2689" };
            Employee ivan = new() { Name = "Ivan", SurName = "Shulga", Position = "3D-Artist", Salary = 6900, ContractNumber = "UHFYU-OI" };
            Employee mary = new() { Name = "Mary", SurName = "Jane", Position = "Animator", Salary = 6000, ContractNumber = "FJUFII-12" };
            Employee kate_anderson = new() { Name = "Kate", SurName = "Anderson", Position = "Feature developer", Salary = 6750, ContractNumber = "FHHFFU-55" };

            HashSet<Employee> project1 = new HashSet<Employee>();
            project1.Add(jordy);
            project1.Add(alex);
            project1.Add(ann);                                            // Add objects ti collection #1
            project1.Add(kate_black);
            project1.Add(john);

            HashSet<Employee> project2 = new HashSet<Employee>();
            project2.Add(jordy);
            project2.Add(mary);
            project2.Add(alex);                                               // Add objects ti collection #2
            project2.Add(kate_anderson);
            project2.Add(ivan);

            Console.WriteLine("=============================   Show team #1   =====================================================================\n");

            DisplaySet(project1);
            Console.WriteLine("=============================   Show team #2   ======================================================================\n");

            DisplaySet(project2);

            HashSet<Employee> same_employee = new HashSet<Employee>(project1.Intersect(project2));

            Console.WriteLine("=============================   Show the same employees for both teams --- Intersect()   ============================\n");

            DisplaySet(same_employee);

            Console.WriteLine("==============================   Show all employees in the company --- Union() =======================================\n");
            HashSet<Employee> all_employees = new HashSet<Employee>(project1.Union(project2));
            DisplaySet(all_employees);

            Console.WriteLine("==============================   Unique employees in team #1 --- ExceptWith() =========================================\n");
            project1.ExceptWith(project2);
            DisplaySet(project1);

            Console.WriteLine("==============================   Team #2 without developers --- RemoveWhere() =========================================\n");
            project2.RemoveWhere(x => x.Position == "Feature developer");
            DisplaySet(project2);


            Console.WriteLine($"###################################################   TASK #2   ########################################################\n");


            // Create the link list --- copy from HashSet<> collection.
            LinkedList<Employee> new_team = new LinkedList<Employee>(all_employees);
            DisplayLList(new_team, "The linked list values:");

            Employee anton = new() { Name = "Anton", SurName = "Tesenko", Position = "Junior C++ developer", Salary = 5100, ContractNumber = "FFFIIDOD-OF" };
            // Add the employee 'Anton' to the beginning of the linked list.
            new_team.AddFirst(anton);
            DisplayLList(new_team, "\n=============================   Test 1: Add 'Anton' to beginning of the list:   =========================================");

            // Move the first node to be the last node.
            LinkedListNode<Employee> mark1 = new_team.First;
            new_team.RemoveFirst();
            new_team.AddLast(mark1);
            DisplayLList(new_team, "================================   Test 2: Move first node to be last node:   ==========================================");

            // Add 'Bob' and 'George' after 'Ann'.
            Employee bob = new() { Name = "Bob", SurName = "Stark", Position = "QA", Salary = 5500, ContractNumber = "GLKFOO" };
            LinkedListNode<Employee> current = new_team.FindLast(ann);
            Employee george = new() { Name = "George", SurName = "Python", Position = "Project manager", Salary = 6500, ContractNumber = "FFFIIDOD-OF" };
            new_team.AddAfter(current, bob);
            new_team.AddAfter(current, george);
            DisplayLList(new_team, "==================================   Test 3: Add 'Bob' and 'George' after 'Ann':   ========================================");

            // Find 'Bob' node.
            Console.WriteLine($"=================================   Test 4: Find 'Bob' node:   ======================================\n{ new_team.Find(bob).Value}\n");

            // Add 'Alina' before 'Ann':
            Employee alina = new() { Name = "Alina", SurName = "Vishnevska", Position = "Game designer", Salary = 6100, ContractNumber = "KKHDD54654-OF" };
            new_team.AddBefore(current, alina);
            DisplayLList(new_team, "==================================   Test 5: Add 'Alina' before 'Ann':   ========================================");

            // Remove 'Bob' by value
            new_team.Remove(bob);
            DisplayLList(new_team, "==================================   Test 6: Remote 'Bob' by value:   ========================================");

            // Remove 'Alina' by node
            current = new_team.FindLast(alina);
            new_team.Remove(current);
            DisplayLList(new_team, "==================================   Test 7: Remote 'Alina' by node:   ========================================");


            // When the linked list is cast to ICollection,
            // the Add method adds a node to the end of the list.
            new_team.RemoveLast();
            ICollection<Employee> icoll = new_team;
            icoll.Add(alina);
            DisplayLList(new_team, "Test 8: Remove last node, cast to ICollection, and add 'Alina' in the end of collection:");

            Console.WriteLine("===================================   Test 9: Copy the LinkedList to an Array:   =====================================");            
            // elements as the linked list.
             Employee[] eArray = new Employee[new_team.Count];                        // Create an array with the same number of
            new_team.CopyTo(eArray, 0);

             foreach (var e in eArray)
             {
                 Console.WriteLine(e);
             }


            Console.WriteLine($"\n=============   Test 10: Before clearing the list. LinkedList Contains('jordy') = { new_team.Contains(jordy)}   ============");
            // Delete all the nodes.
            new_team.Clear();

            Console.WriteLine();
            Console.WriteLine("=============   Test 11: After clearing the list. LinkedList Contains('Jordy') = {0}", new_team.Contains(jordy) + "   ============");

            Console.ReadLine();
        }
    }
 }


