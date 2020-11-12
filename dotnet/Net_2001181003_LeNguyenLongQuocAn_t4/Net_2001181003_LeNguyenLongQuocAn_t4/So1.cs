using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Net_2001181003_LeNguyenLongQuocAn_t4
{
    class So1: IEnumerable <int>
    {
        List<int> mang;
        public So1()
        {
            mang=new List<int>(0);
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
        public string Xuat()
        {
            return string.Join(" ", this);
        }
        public void xoaGT(int s)
        {
            mang = mang.Where(so => so != s).ToList();
        }
        public void xoaVT(int vt)
        {
            mang = mang.Where((value, index) => index != vt).ToList();
        }
        public int timkiemgt(int so)
        {
            return mang.FindIndex(value => value == so);
        }
        public int? timkiemvt(int vt)
        {
            var kq=mang.Where((value,vitri)=> vitri==vt);
            try
            {
                return kq.First();
            }
            catch {
                return null;
            }
        }
        public void thaythegt(int gtcanthay, int sothaythe)
        {
            mang = mang.Select(so =>
                {
                    if (so == gtcanthay)
                    {
                        return sothaythe;
                    }
                    return so;
                }
            ).ToList();
        }
        public void thaythevt(int vtthaythe, int sothaythe)
        {
            mang = mang.Select((value, ind) =>
                {
                    if (ind == vtthaythe)
                    {
                        return sothaythe;
                    }
                    return value;
                }
            ).ToList();
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
