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
    public partial class Form3 : Form
    {
        So a = new So();
        public Form3()
        {
            InitializeComponent();
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            a.Nhap(textBox1.Text);
            textBox2.Text = a.xuat().ToString();
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            a.reset();
            textBox2.Text = " ";
            textBox1.Text = " ";
            textBox1.Focus();
            radioButton1.Checked = false;
            radioButton2.Checked = false;
            radioButton3.Checked = false;
            radioButton4.Checked = false;
            radioButton5.Checked = false;
            radioButton6.Checked = false;
            radioButton7.Checked = false;
            radioButton8.Checked = false;
            radioButton9.Checked = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (radioButton3.Checked)
            {
                int c = a.timkiemtheogiatri(int.Parse(textBox3.Text));
                textBox5.Text = c.ToString();
            }
            else if (radioButton4.Checked)
            {
                int? c = a.imkiemtheovitri(int.Parse(textBox4.Text));
                textBox5.Text = c.ToString();
            }
            else if (radioButton6.Checked)
            {
                a.xoatheogiatri(int.Parse(textBox8.Text));
                textBox2.Text = a.xuat();
            }
            else if (radioButton5.Checked)
            {
                a.xoatheovitri(int.Parse(textBox7.Text));
                textBox2.Text = a.xuat();
            }
            else if (radioButton8.Checked)
            {
                if (int.Parse(textBox9.Text) >= a.ToArray().Length)
                {
                    a.Add(int.Parse(textBox10.Text));
                    textBox2.Text = a.xuat().ToString();
                }
                else
                {
                    a.ThemGT(int.Parse(textBox9.Text), int.Parse(textBox10.Text));
                    textBox2.Text = a.xuat().ToString();
                }
            }
            else if (radioButton9.Checked)
            {
                a.ThaytheGt(int.Parse(textBox17.Text),int.Parse(textBox15.Text));
                textBox2.Text = a.xuat().ToString();
            }
            else if (radioButton7.Checked)
            {
                a.Thaythevitri(int.Parse(textBox16.Text), int.Parse(textBox15.Text));
                textBox2.Text = a.xuat().ToString();
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            a.sapxeptangdan();
            textBox2.Text = a.xuat();
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            a.sapxepgiamdan();
            textBox2.Text = a.xuat();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            try
            {
                textBox14.Text = a.GTLN().ToString();
                textBox13.Text = a.GTNN().ToString();
            }
            catch
            {
                
            }
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox11.Text = a.Tong().ToString();
            textBox6.Text = a.Tongle().ToString();
            textBox12.Text = a.Tongchan().ToString();
        }
    }
}
