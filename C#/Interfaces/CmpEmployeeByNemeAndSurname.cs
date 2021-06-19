using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class CmpEmployeeByNemeAndSurname : IComparer<Employee>
    {
        public int Compare(Employee x, Employee y)
        {
            if (ReferenceEquals(x, y))
                return 0;
            if (x is null)
                return -1;
            if (y is null)
                return 1;
           if (x.Name != y.Name)
            {
                return x.Name.CompareTo(y.Name);
            }
            return x.SurName.CompareTo(y.SurName);
        }
    }
}
