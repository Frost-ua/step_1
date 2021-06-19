using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class CmpEmployeeBySalareAndPosition : IComparer<Employee>
    {
        public int Compare(Employee x, Employee y)
        {
            if (ReferenceEquals(x, y))
                return 0;
            if (x is null)
                return -1;
            if (y is null)
                return 1;
            if (x.Salary != y.Salary)
            {
                if (x.Salary > y.Salary)
                    return 1;
                return -1;
            }
            return x.Position.CompareTo(y.Position);
        }
    }
}
