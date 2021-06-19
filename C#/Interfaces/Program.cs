using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee em1 = new Employee("Jordy", "Frost", "Feature developer", 10000, "AF 3256");
            Employee em2 = new Employee("Alex", "Frost", "Project manager", 8000, "QQ 458I");
            Employee em3 = (Employee)em1.Clone();
            em3.Name = "Julia";
            em3.Position = "Feature developer";
            em3.Salary = 10000;
            em3.ContractNumber = "458OOIP5";
            Employee em4 = new Employee("John", "Byte", "Quality assurance", 6000, "HUY45UYH");
            Employee em5 = new Employee("Kate", "Byte", "3D artist", 7000, "OI56FF");
            Employee em6 = new Employee("Tyler", "Durden", "CEO", 12000, "4500JJ");
            Employee em7 = new Employee("Ann", "Fox", "Feature developer", 8000, "458TY");
            Employee em8 = new Employee("Alex", "Dorsy", "2D artist", 8500, "4589FG45");
            
            Depertment d1 = new();
            d1.AddEmployee(em1);
            d1.AddEmployee(em2);
            d1.AddEmployee(em3);
            d1.AddEmployee(em4);
            d1.AddEmployee(em5);
            d1.AddEmployee(em6);
            d1.AddEmployee(em7);
            d1.AddEmployee(em8);
            Console.WriteLine("=============   Employees before sorting   =================");
            d1.PrintDepartment();
            Console.WriteLine("\nComparison between em1 and em2");
            Console.WriteLine($"em1 and em2 : {em1.CompareTo(em2)}");

            List<Employee> employees = new List<Employee> { em1, em8, em4, em5, em6, em7, em3, em2 };
            Console.WriteLine("\n=============   Employees after sorting --- use default Sort()   =================");
            employees.Sort();
            foreach (Employee obj in employees)
            {
                Console.WriteLine(obj);
            }
            Console.WriteLine("\n=============   Employees after sorting --- use class CmpEmployeeByNemeAndSurname   =================");
            employees.Sort(new CmpEmployeeByNemeAndSurname());
            foreach (Employee obj in employees)
            {
                Console.WriteLine(obj);
            }
            Console.WriteLine("\n=============   Employees after sorting --- use class CmpEmployeeBySalareAndPosition   =================");
            employees.Sort(new CmpEmployeeBySalareAndPosition());
            foreach (Employee obj in employees)
            {
                Console.WriteLine(obj);
            }

            Console.WriteLine("\n=============   IEnumerable --- direct foreach   =================");
            foreach (Employee ex in d1)
            {
                Console.WriteLine(ex);
            }
            Console.WriteLine("\n=============   IEnumerable --- revers foreach   =================");
            foreach (Employee ex in d1.GetReversEmployees())
            {
                Console.WriteLine(ex);
            }
            Console.WriteLine("\n=============   IEnumerable --- employees with salary more than average salary   =================");
            foreach (Employee ex in d1.GetAverageSalary(9000))
            {
                Console.WriteLine(ex);
            }
        }
    }
}
