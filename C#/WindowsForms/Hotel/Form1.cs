using StackExchange.Redis;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Hotel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.monthCalendar1.SelectionRange = new System.Windows.Forms.SelectionRange(DateTime.Now, DateTime.Now);
        }
        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (AgreeCB.Checked)
                SubmitBtn.Enabled = true;
            else
                SubmitBtn.Enabled = false;
        }
        private void SubmitBtnClick_1(object sender, EventArgs e)
        {
            if (!CheckRequiredFields())
            {
                MessageBox.Show("You must fill in the required fields marked *", "Warning!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                Order order = new Order(
                    NameTB.Text,
                    LastNameTB.Text,
                    PhoneTB.Text,
                    EmailTB.Text,
                    (int)AmountPeopleTB.Value,
                    RoomTypeCB.Text,
                    monthCalendar1.SelectionStart,
                    monthCalendar1.SelectionEnd,
                    MessageTB.Text);
                MessageBox.Show("-------------- YOUR ORDER -------------\n\n" + order.ToString(), "Order", MessageBoxButtons.OK, MessageBoxIcon.Information) ;
            } 
        }
        private void CancelBtnClick_1(object sender, EventArgs e)
        {
            NameTB.Clear();
            LastNameTB.Clear();
            MessageTB.Clear();
            EmailTB.Clear();
            PhoneTB.Clear();
            AmountPeopleTB.Value = 1;
            RoomTypeCB.Text = "Standart";
            monthCalendar1.SelectionStart = monthCalendar1.TodayDate;
            monthCalendar1.SelectionEnd = monthCalendar1.TodayDate;
            AgreeCB.Checked = false;
        }
        private void SaveBtn_Click(object sender, EventArgs e)
        {
            if (!CheckRequiredFields())
            {
                MessageBox.Show("You must fill in the required fields marked *", "Warning!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                Order order = new Order(
                    NameTB.Text,
                    LastNameTB.Text,
                    PhoneTB.Text, EmailTB.Text,
                    (int)AmountPeopleTB.Value,
                    RoomTypeCB.Text,
                    monthCalendar1.SelectionStart,
                    monthCalendar1.SelectionEnd,
                    MessageTB.Text);

                SaveFileDialog sfd = new SaveFileDialog();
                sfd.DefaultExt = ".dat";
                sfd.Filter = "Data files|.dat";

                if (sfd.ShowDialog() == DialogResult.OK && sfd.FileName.Length > 0)
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    using (FileStream fs = new FileStream(sfd.FileName, FileMode.Create))
                    {
                        bf.Serialize(fs, order);
                    }
                }
            }
        }
        private void LoadBtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog opd = new OpenFileDialog();
            if (opd.ShowDialog() == DialogResult.OK)
            {
                string a = System.IO.Path.GetExtension(opd.FileName);
                if (Path.GetExtension(opd.FileName) != ".dat")
                {
                    MessageBox.Show("The loaded file must have extension \".dat\"", "Warning!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    using (FileStream fs = new FileStream(opd.FileName, FileMode.Open))
                    {
                        try
                        {
                            var readOrder = (Order)bf.Deserialize(fs);

                            NameTB.Text = readOrder.Name;
                            LastNameTB.Text = readOrder.LastName;
                            PhoneTB.Text = readOrder.Phone;
                            EmailTB.Text = readOrder.Email;
                            AmountPeopleTB.Value = readOrder.Amount;
                            RoomTypeCB.Text = readOrder.RoomType;
                            monthCalendar1.SelectionStart = readOrder.StartDate;
                            monthCalendar1.SelectionEnd = readOrder.EndDate;
                            MessageTB.Text = readOrder.Message;
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show($" {ex.Message}\n The file is corrupt or out of format!", "Warning!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            
                        }
                    }
                }
            }
        }
        private bool CheckRequiredFields()
        {
            if (NameTB.Text == "" || LastNameTB.Text == "" || PhoneTB.Text == "+38 (   )    -" || EmailTB.Text == "")
                return false;
            else
                return true;
        }

        
    }
}
