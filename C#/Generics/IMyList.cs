﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics
{
    public interface IMyList<T>
    {
        T this[int index] { get; set; }
        int IndexOf(T item);
    }
}
