using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;

namespace Exceptions
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee a = new() { Name = "Jordy", SurName = "Frost", Position = "Feature developer", Salary = 12000, ContractNumber = "RTYE12ERF-25" };
            Console.WriteLine(a);
             while (true)
             {
                 try
                 {
                     a.InputName();
                     Console.WriteLine("The name was changed successfully!");
                     break;
                 }
                 catch (Exception ex)
                 {
                     Console.WriteLine(ex.Message);
                 }
             }
             Console.WriteLine(a);
             while (true)
             {
                 try
                 {
                     a.InputSalary();
                     Console.WriteLine("The salary was changed successfully!");
                     break;
                 }
                 catch (Exception ex)
                 {

                     Console.WriteLine(ex.Message);
                 }
             }
            Console.WriteLine(a);
            Console.WriteLine("\n====================   Add salary + 50000   =======================================\n");
            a.AddSalary(50000);
            Console.WriteLine(a);
            Console.WriteLine("\n====================   Department size 0 --- remove employee   =======================================\n");
            Depertment d = new Depertment("Hidden City");
              try
              {
                  d.DeleteEmployee("FJJFJ");
              }
              catch (EmptyDepartmentException ex)
              {
                  Console.WriteLine(ex.Message);
                  Console.WriteLine(ex.Source);
                  Console.WriteLine(ex.StackTrace);
                  Console.WriteLine(ex.HResult);

              }
            d.AddEmployee(a);
           
            Console.WriteLine("\n====================   Department size 1 - it full --- add employee   =======================================\n");
            d.PrintDepartment();
            try
            {
                d.AddEmployee(a);
            }
            catch (FullDepartmentException ex)
            {
                Console.WriteLine(ex.Message);
                
            }
        }
    }
}
