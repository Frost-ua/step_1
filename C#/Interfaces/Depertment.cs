using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
   public class FullDepartmentException : ApplicationException
    {
        public FullDepartmentException(string message = "An employee cannot be added. Department is full!!!") : base(message)
        { }
    }
   public class EmptyDepartmentException : ApplicationException
    {
        public EmptyDepartmentException(string message = "An employee cannot be removed. Department is empty!!!") : base(message)
        { }
    }

    public class Depertment : IEnumerable
    {
        string name;
        const ushort MAX_DEPARTMENT_SIZE = 1/*5*/;
        List<Employee> employee_list;
       public Depertment(string name = "NoName")
        {
            Name = name;
            employee_list = new();
        }
        public string Name
        {
            get => name;
            set => name = !string.IsNullOrWhiteSpace(value) ? value : "NoName";
        }
        public Employee this[int index]
        {
            get => employee_list[index];
            set
            {
                if (index >= 0 && index < employee_list.Count)
                {
                    employee_list[index] = value;
                }
            }
        }
        public Employee this[string contract_number]
        {
            get
            {
                for (int i = 0; i < employee_list.Count; i++)
                {
                    if (employee_list[i].ContractNumber == contract_number)
                    {
                        return employee_list[i];
                    }
                }
                return null;
            }
        }
        public void AddEmployee(Employee employee)
        {
            if (employee_list.Count >= MAX_DEPARTMENT_SIZE)
                throw new FullDepartmentException();
            employee_list.Add(employee);
        }
        public void DeleteEmployee(string contract_number)
        {
            if (employee_list.Count <= 0)
                throw new EmptyDepartmentException();
            bool is_deleted = false;
            for (int i = 0; i < employee_list.Count; i++)
            {
                if (employee_list[i].ContractNumber == contract_number)
                {
                     employee_list.RemoveAt(i);
                     is_deleted = true;
                     break;
                }
            }
            if (!is_deleted)
            {
                Console.WriteLine($"Employee with contract number {contract_number} is not found.");
            }
        }
        public void DeleteEmployee(string name, string surname)
        {
            if (employee_list.Count <= 0)
                throw new EmptyDepartmentException();
            bool is_deleted = false;
            for (int i = 0; i < employee_list.Count; i++)
            {
                if (employee_list[i].Name == name && employee_list[i].SurName == surname)
                {
                    employee_list.RemoveAt(i);
                    is_deleted = true;
                    break;
                }
            }
            if (!is_deleted)
            {
                Console.WriteLine($"Employee with name {name} and last name {surname} is not found.");
            }
        }
        public void PrintDepartment()
        {
            foreach (var employee in employee_list)
            {
                Console.WriteLine(employee);
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return employee_list.GetEnumerator(); 
        }
        public IEnumerable<Employee> GetReversEmployees()
        {
            for (int i = employee_list.Count - 1; i >= 0; i--)
            {
                yield return employee_list[i];
            }
        
        }
        public IEnumerable<Employee> GetAverageSalary(int avg_salary)
        {
            foreach (Employee ex in employee_list)
            {
                if (ex.Salary >= avg_salary)
                {
                    yield return ex;
                }
            }
        }
    }
}
