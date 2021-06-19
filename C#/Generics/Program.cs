using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;

namespace Generics
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee jordy = new Employee("Jordy", "Frost", "Feature developer", 7000, "FF56-2567");
            Employee alex = new Employee("Alex", "Frost", "QA Lead", 5500, "GTUY-2362");
            Employee kate = new Employee("Kate", "Black", "3D Artist", 5800, "FOUJ-12K8");
            Employee ann = new Employee("Ann", "Palmer", "Feature developer", 6200, "YUIO-UDTT");
            Employee john = new Employee("John", "Anderson", "Animator", 5900, "FU36-2689");

            MyList< Employee > employees_list = new();
            employees_list.Add(jordy);
            employees_list.Add(alex);
            employees_list.Add(kate);
            employees_list.Add(ann);
            employees_list.Add(john);

            Employee result0 = employees_list.Find(x => x.Salary > 5500 && x.Salary < 6500);
            Console.WriteLine($"====================   T Find(Predicate<T> match); Salary Between 5500 and 6500    =================\n{result0}");
            List<Employee> list_result = employees_list.FindAll(x => x.Salary > 5500 && x.Salary < 6500);
            Console.WriteLine($"\n====================   List<T> FindAll(Predicate<T> match)	Salary Between 5500 and 6500     =================\n");
            foreach (var em in list_result)
            {
                Console.WriteLine(em);
            }

            Console.WriteLine($"\n====================   Print all employees after adding to MyList<T> - use foreach  ================= \n");
            foreach (var em in employees_list)
            {
                Console.WriteLine(em);
            }

            Console.WriteLine($"====================   T this[int index]  ================= \n{employees_list[1]}");
            int index = employees_list.IndexOf(ann);
            Console.WriteLine($"\n====================   int IndexOf(T item); ================= \nIndex : {index}");
            bool result = employees_list.Contains(john);
            Console.WriteLine($"\n====================   bool Contains(T item);  ================= \n{result}");
            bool result1 = employees_list.Remove(ann);
            Console.WriteLine($"\n====================   bool Remove(T item);  ================= \n{result1}");

            Console.WriteLine($"====================   Print all employees after  Remove(T item) - use foreach  ================= \n");
            foreach (var em in employees_list)
            {
                Console.WriteLine(em);
            }
            employees_list.RemoveAt(1);
            Console.WriteLine($"====================   Print all employees after  RemoveAt(int index) - use foreach  ================= \n");
            foreach (var em in employees_list)
            {
                Console.WriteLine(em);
            }
            employees_list.Insert(1, new Employee ("Julia", "Fox", "2D Artist", 4100, "KIJU-POOP"));
            Console.WriteLine($"====================   Print all employees after  Insert(int index, T item) - use foreach  ================= \n");
            foreach (var em in employees_list)
            {
                Console.WriteLine(em);
            }
            
            int result3 = employees_list.IndexOf(kate);
            Console.WriteLine($"====================   IndexOf (T item);   =================\nIndex : {result3}");
            employees_list.Clear();
            Console.WriteLine($"====================   void Clear();    =================\nCapacity : {employees_list.Сapacity}\nCount : {employees_list.Count}");
            
        }
    }
}
