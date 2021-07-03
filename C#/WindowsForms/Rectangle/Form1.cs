using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
  
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = $"X: {e.X}, Y: {e.Y}";
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            
            if (e.Button == MouseButtons.Right)
            {
                this.label1.Location = new Point(this.ClientSize.Width/2 - 50, this.ClientSize.Height/2 - 30);
                label1.Text = $"Window size:\nX:{this.ClientSize.Width}, Y: {this.ClientSize.Height}";
            }
            if (e.Button == MouseButtons.Left)
            {
                if (ModifierKeys == Keys.Control)
                {
                    this.Close();
                }

                if (e.X < 10 || e.X > this.ClientSize.Width - 10 || e.Y < 10 || e.Y > this.ClientSize.Height - 10)
                {
                    MessageBox.Show($"The point is located outside the rectangle.", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else if (e.X == 10 || e.X == this.ClientSize.Width - 10 || e.Y == 10 || e.Y == this.ClientSize.Height - 10)
                {
                    MessageBox.Show($"The point is located on the border.", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show($"The point is located inside the rectangle.", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
               

            }
        }

     
    }
}
