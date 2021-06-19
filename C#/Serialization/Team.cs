using Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Serialization
{
    public class Team
    {
        public List<Employee> team_name = new();
        public Team()
        { }
        public void AddEmployeeToTeam(Employee em)
        {
            team_name.Add(em);
        }
        public void ShowTeam()
        {
            foreach (var item in team_name)
            {
                Console.WriteLine(item);
            }
        }
    }
}
