using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NET_2001181272_HuynhThanhPhuong_T8
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void btnShow_Click(object sender, EventArgs e)
        {
            using (DataClasses1DataContext db = new DataClasses1DataContext())
            {
                var lops = from lop in db.LOPs
                          join k in db.KHOAs
                          on lop.MA_KHOA equals k.MA_KHOA
                          select new
                          {
                              MA_LOP = lop.MA_LOP,
                              MA_KHOA = k.MA_KHOA,
                              TENKHOA = k.TENKHOA
                          };
                int i = 0;
                foreach (var l in lops)
                {
                    lvLop.Items.Add(new ListViewItem(new string[] { (++i).ToString(), l.MA_LOP, l.MA_KHOA, l.TENKHOA }));
                }
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {        
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("You Want Exit Proram??", "Wanring", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.Yes)
            {
                Application.Exit();
            }
            else
            {
                return;
            }
        }
    }
}
