using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Net_LeNguyenLongQuocAn_T6
{
    public partial class Form4 : Form 
    {
        public Form4()
        {
            InitializeComponent();
        }
        ListViewItem itemedit = null;
        private void Form4_Load(object sender, EventArgs e)
        {
            textBox1.Focus();
            button2.Enabled = false;
            button3.Enabled = false;
            
        }
        bool a = true;
        private void button1_Click(object sender, EventArgs e)
        {
            button2.Enabled = true;
            if (a)
            {
                textBox1.Focus();
                button1.Text = "Hủy";
                a = false;
            }
            
            else 
            {
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                textBox4.Clear();
                textBox1.Focus();
                button1.Text = "Thêm";
                button2.Enabled = false;
                a = true;
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            string stk = textBox1.Text;
            string ten = textBox2.Text;
            string diachi = textBox3.Text;
            string sotien = textBox4.Text;
            ListViewItem item = listView1.Items.Add((listView1.Items.Count + 1).ToString());
            item.SubItems.Add(stk.ToString());
            item.SubItems.Add(ten.ToString());
            item.SubItems.Add(diachi.ToString());
            item.SubItems.Add(sotien.ToString());
            

            
        }

         
        private void button3_Click(object sender, EventArgs e)
        {
            foreach (ListViewItem a in listView1.SelectedItems)
            {
                listView1.Items.Remove(a);
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            button3.Enabled = true;
            if (listView1.SelectedItems.Count == 0)
            {
                button3.Enabled = false;
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                textBox4.Clear();
                textBox1.Focus();
                return;
            }
            itemedit=listView1.SelectedItems[0];
            ListViewItem.ListViewSubItem sub1 = itemedit.SubItems[1];
            ListViewItem.ListViewSubItem sub2 = itemedit.SubItems[2];
            ListViewItem.ListViewSubItem sub3 = itemedit.SubItems[3];
            ListViewItem.ListViewSubItem sub4 = itemedit.SubItems[4];
            textBox1.Text = sub1.Text;
            textBox2.Text = sub2.Text;
            textBox3.Text = sub3.Text;
            textBox4.Text = sub4.Text;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            int k=0;
            foreach (ListViewItem a in listView1.Items)
            {
                ListViewItem.ListViewSubItem sub1 = a.SubItems[4];
                k+= int.Parse(sub1.Text);
                textBox5.Text = k.ToString();
            }
        }
    }
}
