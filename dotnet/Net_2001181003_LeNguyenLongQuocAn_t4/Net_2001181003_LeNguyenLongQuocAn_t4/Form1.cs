using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Net_2001181003_LeNguyenLongQuocAn_t4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            tinhtoan tt = new tinhtoan();
            tt.a = int.Parse(textBox1.Text);
            tt.b = int.Parse(textBox2.Text);
            if (radioButton1.Checked)
            {
                textBox3.Text = tt.tong().ToString();
            }
            else if (radioButton2.Checked)
            {
                textBox3.Text = tt.tru().ToString();
            }
            else if (radioButton3.Checked)
            {
                textBox3.Text = tt.nhan().ToString();
            }
            else
            {
                textBox3.Text = tt.chia().ToString();
            }
        }
    }
}
