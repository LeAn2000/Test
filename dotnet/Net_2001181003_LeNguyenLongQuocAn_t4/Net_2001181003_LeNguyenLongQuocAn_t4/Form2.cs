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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PTbac1 p1 = new PTbac1();
            p1.a = int.Parse(textBox1.Text);
            p1.b = int.Parse(textBox2.Text);
            PTbac2 p2= new PTbac2();
            p2.a=int.Parse(textBox1.Text);
            p2.b=int.Parse(textBox2.Text);
            p2.c=int.Parse(textBox3.Text);
            if (radioButton1.Checked)
            {
                
                if (p1.a == 0)
                {
                    if (p1.b == 0)
                    {
                        textBox4.Text = "Phương trình có vô số nghiệm";
                    }
                    else
                    {
                        textBox4.Text = "Phương trình vô nghiệm";
                    }
                }
                else
                {
                    textBox4.Text = p1.giai().ToString();
                }
            }
            else if (radioButton2.Checked)
            {
                if (p2.a == 0)
                {
                    if (p2.b == 0)
                    {
                        if (p2.c == 0)
                        {
                            textBox4.Text = "Phương trình có vô số nghiệm";
                        }
                        else
                        {
                            textBox4.Text = "Phương trình vô nghiệm";
                        }
                    }
                    else
                    {
                        textBox4.Text = p2.giai().ToString();
                    }
                }
                else
                {
                    double d = p2.delta();
                    if (d < 0)
                    {
                        textBox4.Text = "phương trình vô nghiệm";
                    }
                    else if (d == 0)
                    {
                        textBox4.Text = p2.ngiemkep().ToString();
                    }
                    else
                    {
                        textBox4.Text = " x1 =" + p2.nghiemd1().ToString() + " ;x2 =" + p2.nghiemd2().ToString();
                    }
                }
            }
        }
            
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            textBox3.Visible = false;
            button1.Visible = true;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            textBox3.Visible = true;
            button1.Visible = true;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            textBox1.Select();
            button1.Visible = false;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
