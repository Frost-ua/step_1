using Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Serialization
{
    [Serializable]
    public class Project
    {
        public Dictionary<uint, Employee> project_name = new();
        public Project()
        { }
        public void AddEmployeeToProject(Employee em)
        {
            project_name.Add(em.Id,em);
        }
        public void ShowTeam()
        {
            foreach (var item in project_name)
            {
                Console.WriteLine(item.Value);
            }
        }
    }
}
