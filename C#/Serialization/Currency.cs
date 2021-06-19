using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Serialization
{
    public class Currency
    {
        public Currency(string ccy, string base_ccy, string buy, string sale)
        {
            this.Ccy = ccy;
            this.Base_ccy = base_ccy;
            this.Buy = buy;
            this.Sale = sale;
        }
        public string Ccy { get; set; }
        public string Base_ccy { get; set; }
        public string Buy { get; set; }
        public string Sale { get; set; }
        public override string ToString()
        {
            return ($"{Ccy} / {Base_ccy, -10}BUY : {Buy, -15} SALE : {Sale}");
        }
    }
}
