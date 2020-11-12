using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NET_2001181272_HuynhThanhPhuong_T8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            loadQLSV();
        }
        public void loadQLSV()
        {
            using (DataClasses1DataContext qlsv = new DataClasses1DataContext())
            {
                cbLop.DataSource = qlsv.SINHVIENs.Select(malop => malop.MALOP);
                dataGridView1.DataSource = qlsv.SINHVIENs.ToList();
            }
            reset();
        }
        public void reset()
        {
            txtID.ResetText();
            txtName.ResetText();
        }
        private void btnInsert_Click(object sender, EventArgs e)
        {
            using (DataClasses1DataContext qlsv = new DataClasses1DataContext())
            {
                SINHVIEN sv = new SINHVIEN();
                sv.MALOP = cbLop.GetItemText(this.cbLop.SelectedItem);
                sv.MA_SINHVIEN = txtID.Text; 
                sv.HOTEN = txtName.Text;
                sv.NGAYSINH = dateTimePicker1.Value;
                qlsv.SINHVIENs.InsertOnSubmit(sv);
                qlsv.SubmitChanges();
                loadQLSV();
                reset();
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow == null)
            {
                return; 
            }
            using (DataClasses1DataContext qlsv = new DataClasses1DataContext())
            {
                SINHVIEN svOld = dataGridView1.CurrentRow.DataBoundItem as SINHVIEN;
                SINHVIEN svNew = qlsv.SINHVIENs.Where(maSV => maSV.MA_SINHVIEN == svOld.MA_SINHVIEN).First();
                qlsv.SINHVIENs.DeleteOnSubmit(svNew);
                qlsv.SubmitChanges();
                loadQLSV();
            }
            reset();
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            using (DataClasses1DataContext qlsv = new DataClasses1DataContext())
            {
                SINHVIEN svOld = dataGridView1.CurrentRow.DataBoundItem as SINHVIEN;
                SINHVIEN svNew = qlsv.SINHVIENs.Where(maSV => maSV.MA_SINHVIEN == svOld.MA_SINHVIEN).First();
                svNew.MA_SINHVIEN = txtID.Text;
                svNew.HOTEN = txtName.Text;
                svNew.NGAYSINH = dateTimePicker1.Value;
                qlsv.SubmitChanges();
                loadQLSV();
            }
            reset();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            SINHVIEN sv = dataGridView1.CurrentRow.DataBoundItem as SINHVIEN;
            cbLop.SelectedItem = sv.MALOP;
            txtID.Text = sv.MA_SINHVIEN;
            txtName.Text = sv.HOTEN;
        }
    }
}