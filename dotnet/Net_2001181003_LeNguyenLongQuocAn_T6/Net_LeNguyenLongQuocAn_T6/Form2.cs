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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        ListViewItem itemEdit = null;
        private void button1_Click(object sender, EventArgs e)
        {
            string ms = textBox1.Text;
            string ht = textBox2.Text;
            ListViewItem item= new ListViewItem(new string [] {ms,ht} );
            listView1.Items.Add(item);
            textBox1.Clear();
            textBox2.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (ListViewItem a in listView1.SelectedItems)
            {
                listView1.Items.Remove(a);
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count == 0)
            {
                return;
            }
            itemEdit = listView1.SelectedItems[0];
            textBox1.Text = itemEdit.Text;
            ListViewItem.ListViewSubItem sub1 = itemEdit.SubItems[1];
            textBox2.Text = sub1.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            itemEdit.Text = textBox1.Text;
            itemEdit.SubItems[1].Text = textBox2.Text;
        }
    }
}
