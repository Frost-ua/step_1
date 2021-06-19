using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    [Serializable]
    public class Employee : ICloneable, IComparable
    {
        static uint last_id = 0;
        public uint id = ++last_id;
        string name;
        string surname;
        string position;
        ushort salary;
        string contract_number;
        const ushort MIN_SALARY = 5000;
        public int[] points;
        const int Points_size = 5;

        Employee() { }
        public Employee(string name = "NoName", string surname = "Unknown", string position = "Unknown", ushort salary = 0, string contract_number = "Unknown")
        {
            Name = name;
            SurName = surname;
            Position = position;
            Salary = salary;
            ContractNumber = contract_number;
            points = new int[Points_size];
            AddPoint();
        }
        public uint Id
        {
            get => id;
            
        }
        public string Name
        {
            get => name;
            set => name = !string.IsNullOrWhiteSpace(value) ? value : "NoName";
        }
        public string SurName
        {
            get => surname;
            set => surname = !string.IsNullOrWhiteSpace(value) ? value : "Unknown";
        }
        public string Position
        {
            get => position;
            set => position = !string.IsNullOrWhiteSpace(value) ? value : "Unknown";
        }
        public ushort Salary
        {
            get => salary;
            set => salary = value >= MIN_SALARY ? value : MIN_SALARY;
        }
        public string ContractNumber
        {
            get => contract_number;
            set => contract_number = !string.IsNullOrWhiteSpace(value) ? value : "Unknown";
        }
        public override string ToString()
        {
            return ($"ID : {Id, -10}Contract : {ContractNumber, -15}Salary :{Salary, -10}Position : {Position, -20} \tName : {Name, -10}Surname : {SurName, -10}\nPoints :\t{string.Join("\t", points)}");
        }
        public void AddPoint()
        {
            var rand = new Random();
            for (int i = 0; i < points.Length; i++)
            {
                points[i] = rand.Next(1, 10);
            }
                    
        }
        public void AddPoint(int[] p1)
        {
            points = p1;
            


        }
        public int[] GetPoints()
        {
            return points;
        }
        public object Clone()
        {
            Employee clone = new Employee(Name = this.Name, SurName = this.SurName, Position = this.Position, Salary = this.Salary, ContractNumber = this.ContractNumber);
            return clone;
        }
        public int CompareTo(object obj)
        {
            Employee ex = obj as Employee;
            if (ex is null)
            {
                throw new FormatException("Error type object! Expected Employee.");
            }
            if (this.ContractNumber != ex.ContractNumber)
            {
                return this.ContractNumber.CompareTo(ex.ContractNumber);
            }
            else if (this.Position != ex.Position)
            {
                return this.Position.CompareTo(ex.Position);
            }
            else if (this.Salary != ex.Salary)
            {
                if (this.Salary > ex.Salary)
                    return 1;
                return -1;
            }
            else if (this.Name != ex.Name)
            {
                return this.Name.CompareTo(ex.Name);
            }
            return this.SurName.CompareTo(ex.SurName);
            
        }
        public void InputName()
        {
            Console.WriteLine("\nEnter the name : ");
            string name, surname;
            name = Console.ReadLine();
            bool is_name = name.All(Char.IsLetter);
                if (!is_name)
                    throw new Exception("Incorrect name. The name must contain from letters only!");
                this.Name = name;
               
            Console.WriteLine("\nEnter the last name : ");
            surname = Console.ReadLine();
            bool is_surname = surname.All(Char.IsLetter);

            if (!is_surname)
                throw new Exception("Incorrect last name. The last name must contain from letters only!");
            this.SurName = surname;
        }
        public void InputSalary()
        {
            Console.WriteLine("\nEnter salary : ");
            ushort salary;
            salary = ushort.Parse(Console.ReadLine());
            if (salary > MIN_SALARY && salary < ushort.MaxValue)
            {
                this.Salary = salary;
            }
            else
            {
                throw new Exception($"Incorrect salary! Salary must be more than min salary {MIN_SALARY} and less than max salary {ushort.MaxValue}");

            }
        }
        public void AddSalary(ushort add)
        {
                try
                {
                    checked
                    {
                        Salary += add;
                    } 
                }
                catch (Exception)
                {

                    Console.WriteLine($"The salary was not increasedSalary!\nIt can not be more than {ushort.MaxValue}!");
                }
        }
        public override bool Equals(object obj)
        {
            Employee p = obj as Employee;
            if (p is null)
            {
                return false;
            }
            return Name.Equals(p.Name) && SurName.Equals(p.SurName) && Position.Equals(p.Position) && Salary.Equals(p.Salary) && ContractNumber.Equals(p.ContractNumber);
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }
}
