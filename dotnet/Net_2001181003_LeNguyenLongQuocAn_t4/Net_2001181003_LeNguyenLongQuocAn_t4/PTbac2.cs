using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Net_2001181003_LeNguyenLongQuocAn_t4
{
    class PTbac2
    {
        // ax2+bx+c=0
        public double a { get; set; }
        public double b { get; set; }
        public double c { get; set; }

        public double delta()
        {
            return b * b - 4 * a * c;
        }
        public double ngiemkep()
        {
            return -b / 2 * a;
        }
        public double nghiemd1()
        {
            double x1 = (-b + Math.Sqrt(delta())) / 2 * a;
            return x1;
        }
        public double nghiemd2()
        {
            double x2 = (-b - Math.Sqrt(delta())) / 2 * a;
            return x2;
        }
        public double giai()
        {
            return -c / b;
        }

    }
}
