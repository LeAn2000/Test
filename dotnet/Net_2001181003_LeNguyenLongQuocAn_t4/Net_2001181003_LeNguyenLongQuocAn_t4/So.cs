using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Net_2001181003_LeNguyenLongQuocAn_t4
{
    class So : IEnumerable<int>
    {
        List<int> mang;
        public So()
        {
            mang = new List<int>(0);
        }
        public void Add(int so)
        {
            mang.Add(so);
        }
        public void Nhap(string dayso)
        {
            dayso = dayso.Trim();
            dayso = Regex.Replace(dayso, @"\s+", " ");
            string[] ds = dayso.Split(' ');
            mang.Clear();
            foreach (string so in ds)
            {
                Add(int.Parse(so));
            }
        }
        public void sapxeptangdan()
        {
            mang.Sort((a, b) => a.CompareTo(b));
        }
        public void sapxepgiamdan()
        {
            mang.Sort((a, b) => b.CompareTo(a));
        }
        public int timkiemtheogiatri(int so)
        {
            return mang.FindIndex(value => value == so);
        }
        public int? imkiemtheovitri(int index)
        {
            var kq = mang.Where((val, ind) => index == ind);
            try
            {
                return kq.First();
            }
            catch
            {
                return null;
            }
        }
        public void xoatheogiatri(int so)
        {
            mang = mang.Where(value => value != so).ToList();
        }
        public void xoatheovitri(int vitri)
        {
            mang = mang.Where((value, index) => index != vitri).ToList();
        }
        public void ThemGT(int vt, int so)
        {
            mang.Insert(vt, so);
        }
        public void reset()
        {
            mang.Clear();
        }
        public string xuat()
        {
            return string.Join(" ", this);
        }
        public void ThaytheGt(int gtcanthay, int gtthaythe)
        {
            mang = mang.Select(so =>
            {
                if (so == gtcanthay)
                {
                    return gtthaythe;
                }
                return so;
            }
            ).ToList();
        }
        public void Thaythevitri(int vtcanthay, int gtthaythe)
        {
            mang = mang.Select((so, index) =>
            {
                if (index == vtcanthay)
                {
                    return gtthaythe;
                }
                return so;
            }
            ).ToList();
        }
        public int Tong()
        {
            int n;
            return n = mang.Sum();
        }
        public int Tongle()
        {
            List<int> mang1 = mang.Where(value => value % 2 != 0).ToList();
            int n = mang1.Sum();
            return n;
        }
        public int Tongchan()
        {
            List<int> mang2 = mang.Where(value => value % 2 == 0).ToList();
            int n = mang2.Sum();
            return n;
        }
        public int GTLN()
        {
            int a = mang.Max();
            return a;
        }
        public int GTNN()
        {
            int a = mang.Min();
            return a;
        }
        public IEnumerator<int> GetEnumerator()
        {
            return mang.GetEnumerator();
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return mang.GetEnumerator();
        }
    }
}
