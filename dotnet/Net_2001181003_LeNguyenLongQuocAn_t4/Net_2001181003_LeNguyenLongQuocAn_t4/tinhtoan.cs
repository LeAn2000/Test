using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Net_2001181003_LeNguyenLongQuocAn_t4
{
    class tinhtoan
    {
        public double a { get; set; }
        public double b { get; set; }

        public double tong()
        {
            return a + b;
        }
        public double tru()
        {
            return a - b;
        }
        public double nhan()
        {
            return a * b;
        }
        public double chia()
        {
            return a / b;
        }
    }
}
