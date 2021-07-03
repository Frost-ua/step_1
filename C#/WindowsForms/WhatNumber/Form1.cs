using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WhatNumber
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void PushMe_Click(object sender, EventArgs e)
        {
            bool is_number = false;
            Random rnd = new Random();
            int random = rnd.Next(0, 100), bottom = 0, top = 100, counter = 1, tmp_top = top, tmp_bottom = bottom;
            while (!is_number)
            {
                DialogResult res1 = MessageBox.Show($"Is it your number?\n{random, 15}", "Question", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (res1 == DialogResult.Yes)
                {
                    MessageBox.Show($"          I did it\n         in {counter} tries.", "Result", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    DialogResult res3 = MessageBox.Show($"Shall we play one more time?", "Question", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    if (res3 == DialogResult.Yes)
                    {
                        is_number = false;
                        counter = 1;
                        bottom = 0;
                        top = 100;
                        tmp_bottom = 0;
                        tmp_top = 0;
                        random = rnd.Next(0, 100);
                    }
                    else
                    {
                        is_number = true;
                        this.Close();
                    }
                }
                else
                {
                    DialogResult res2 = MessageBox.Show($"Is your number bigger than {random}?", "Question", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    ++counter;
                    if (res2 == DialogResult.Yes)
                    {
                        bottom = random + 1;
                        IsOutRange(bottom, top);
                        random = rnd.Next(bottom, top);
                    }
                    else if(res2 == DialogResult.No)
                    {
                        top = random - 1;
                        IsOutRange(bottom, top);
                        random = rnd.Next(bottom, top);
                    }
                    IsOutRange(bottom, top);

                }
            }
        }
        private void IsOutRange(int bottom, int top)
        {
            if (top < 0 || bottom > 100)
            {
                MessageBox.Show($"You are cheater!!!", "Cheater!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.Close();
            }
            if (top - bottom == -1)
            {
                MessageBox.Show($"You are cheater!!!", "Cheater!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.Close();
            }
         
        }
    }
}
