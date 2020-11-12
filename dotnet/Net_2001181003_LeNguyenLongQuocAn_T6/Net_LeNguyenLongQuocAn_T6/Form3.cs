using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Net_LeNguyenLongQuocAn_T6
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            saveFileDialog1.Filter = "File txt |*.txt";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                StreamWriter writer = new StreamWriter(saveFileDialog1.FileName);
                writer.Write(textBox1.Text);
                writer.Close();
            }
            textBox1.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "File txt |*.txt";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                StreamReader reader = new StreamReader(openFileDialog1.FileName);
                textBox1.Text = reader.ReadToEnd();
                reader.Close();
            }
        }
    }
}
