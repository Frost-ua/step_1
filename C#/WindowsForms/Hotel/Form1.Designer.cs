
namespace Hotel
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.NameTB = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.LastNameTB = new System.Windows.Forms.TextBox();
            this.EmailTB = new System.Windows.Forms.TextBox();
            this.PhoneTB = new System.Windows.Forms.MaskedTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.AmountPeopleTB = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.RoomTypeCB = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.MessageTB = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.SubmitBtn = new System.Windows.Forms.Button();
            this.CancelBtn = new System.Windows.Forms.Button();
            this.AgreeCB = new System.Windows.Forms.CheckBox();
            this.SaveBtn = new System.Windows.Forms.Button();
            this.LoadBtn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.AmountPeopleTB)).BeginInit();
            this.SuspendLayout();
            // 
            // NameTB
            // 
            this.NameTB.BackColor = System.Drawing.SystemColors.HighlightText;
            this.NameTB.ForeColor = System.Drawing.SystemColors.GrayText;
            this.NameTB.Location = new System.Drawing.Point(153, 78);
            this.NameTB.Name = "NameTB";
            this.NameTB.Size = new System.Drawing.Size(152, 22);
            this.NameTB.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Lucida Handwriting", 17F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(246, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(355, 37);
            this.label1.TabIndex = 1;
            this.label1.Text = "Welcome to the hotel";
            // 
            // LastNameTB
            // 
            this.LastNameTB.BackColor = System.Drawing.SystemColors.HighlightText;
            this.LastNameTB.ForeColor = System.Drawing.SystemColors.GrayText;
            this.LastNameTB.Location = new System.Drawing.Point(153, 106);
            this.LastNameTB.Name = "LastNameTB";
            this.LastNameTB.Size = new System.Drawing.Size(152, 22);
            this.LastNameTB.TabIndex = 0;
            // 
            // EmailTB
            // 
            this.EmailTB.BackColor = System.Drawing.SystemColors.HighlightText;
            this.EmailTB.ForeColor = System.Drawing.SystemColors.GrayText;
            this.EmailTB.Location = new System.Drawing.Point(153, 162);
            this.EmailTB.Name = "EmailTB";
            this.EmailTB.Size = new System.Drawing.Size(152, 22);
            this.EmailTB.TabIndex = 0;
            // 
            // PhoneTB
            // 
            this.PhoneTB.Location = new System.Drawing.Point(153, 134);
            this.PhoneTB.Mask = "+38 (000) 000-0000";
            this.PhoneTB.Name = "PhoneTB";
            this.PhoneTB.Size = new System.Drawing.Size(152, 22);
            this.PhoneTB.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(94, 137);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "*Phone:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(94, 83);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 17);
            this.label3.TabIndex = 3;
            this.label3.Text = "*Name:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(65, 109);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(83, 17);
            this.label4.TabIndex = 3;
            this.label4.Text = "*Last name:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(94, 162);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(51, 17);
            this.label5.TabIndex = 3;
            this.label5.Text = "*Email:";
            // 
            // AmountPeopleTB
            // 
            this.AmountPeopleTB.Location = new System.Drawing.Point(153, 191);
            this.AmountPeopleTB.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.AmountPeopleTB.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.AmountPeopleTB.Name = "AmountPeopleTB";
            this.AmountPeopleTB.Size = new System.Drawing.Size(46, 22);
            this.AmountPeopleTB.TabIndex = 4;
            this.AmountPeopleTB.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(20, 193);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(123, 17);
            this.label6.TabIndex = 3;
            this.label6.Text = "Amount of people:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(60, 226);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(80, 17);
            this.label7.TabIndex = 3;
            this.label7.Text = "Room type:";
            // 
            // RoomTypeCB
            // 
            this.RoomTypeCB.ForeColor = System.Drawing.SystemColors.ControlText;
            this.RoomTypeCB.FormattingEnabled = true;
            this.RoomTypeCB.Items.AddRange(new object[] {
            "Economy",
            "Standard",
            "Luxury"});
            this.RoomTypeCB.Location = new System.Drawing.Point(153, 226);
            this.RoomTypeCB.Name = "RoomTypeCB";
            this.RoomTypeCB.Size = new System.Drawing.Size(121, 24);
            this.RoomTypeCB.TabIndex = 5;
            this.RoomTypeCB.Text = "Standart";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(87, 260);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(53, 17);
            this.label8.TabIndex = 3;
            this.label8.Text = "Period:";
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.Location = new System.Drawing.Point(153, 260);
            this.monthCalendar1.MaxSelectionCount = 31;
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.ShowToday = false;
            this.monthCalendar1.TabIndex = 6;
            // 
            // MessageTB
            // 
            this.MessageTB.BackColor = System.Drawing.SystemColors.HighlightText;
            this.MessageTB.ForeColor = System.Drawing.SystemColors.GrayText;
            this.MessageTB.Location = new System.Drawing.Point(525, 78);
            this.MessageTB.Multiline = true;
            this.MessageTB.Name = "MessageTB";
            this.MessageTB.Size = new System.Drawing.Size(325, 106);
            this.MessageTB.TabIndex = 0;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(444, 78);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(69, 17);
            this.label9.TabIndex = 3;
            this.label9.Text = "Message:";
            // 
            // SubmitBtn
            // 
            this.SubmitBtn.Enabled = false;
            this.SubmitBtn.Location = new System.Drawing.Point(525, 415);
            this.SubmitBtn.Name = "SubmitBtn";
            this.SubmitBtn.Size = new System.Drawing.Size(104, 51);
            this.SubmitBtn.TabIndex = 7;
            this.SubmitBtn.Text = "Submit";
            this.SubmitBtn.UseVisualStyleBackColor = true;
            this.SubmitBtn.Click += new System.EventHandler(this.SubmitBtnClick_1);
            // 
            // CancelBtn
            // 
            this.CancelBtn.Location = new System.Drawing.Point(746, 415);
            this.CancelBtn.Name = "CancelBtn";
            this.CancelBtn.Size = new System.Drawing.Size(104, 51);
            this.CancelBtn.TabIndex = 7;
            this.CancelBtn.Text = "Cancel";
            this.CancelBtn.UseVisualStyleBackColor = true;
            this.CancelBtn.Click += new System.EventHandler(this.CancelBtnClick_1);
            // 
            // AgreeCB
            // 
            this.AgreeCB.AutoSize = true;
            this.AgreeCB.Location = new System.Drawing.Point(525, 208);
            this.AgreeCB.Name = "AgreeCB";
            this.AgreeCB.Size = new System.Drawing.Size(296, 21);
            this.AgreeCB.TabIndex = 8;
            this.AgreeCB.Text = "I agree to the hotel conditions and policies";
            this.AgreeCB.UseVisualStyleBackColor = true;
            this.AgreeCB.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // SaveBtn
            // 
            this.SaveBtn.Location = new System.Drawing.Point(525, 275);
            this.SaveBtn.Name = "SaveBtn";
            this.SaveBtn.Size = new System.Drawing.Size(76, 28);
            this.SaveBtn.TabIndex = 9;
            this.SaveBtn.Text = "Save ...";
            this.SaveBtn.UseVisualStyleBackColor = true;
            this.SaveBtn.Click += new System.EventHandler(this.SaveBtn_Click);
            // 
            // LoadBtn
            // 
            this.LoadBtn.Location = new System.Drawing.Point(525, 309);
            this.LoadBtn.Name = "LoadBtn";
            this.LoadBtn.Size = new System.Drawing.Size(76, 28);
            this.LoadBtn.TabIndex = 10;
            this.LoadBtn.Text = "Load ...";
            this.LoadBtn.UseVisualStyleBackColor = true;
            this.LoadBtn.Click += new System.EventHandler(this.LoadBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(888, 539);
            this.Controls.Add(this.LoadBtn);
            this.Controls.Add(this.NameTB);
            this.Controls.Add(this.LastNameTB);
            this.Controls.Add(this.PhoneTB);
            this.Controls.Add(this.EmailTB);
            this.Controls.Add(this.AmountPeopleTB);
            this.Controls.Add(this.RoomTypeCB);
            this.Controls.Add(this.monthCalendar1);
            this.Controls.Add(this.MessageTB);
            this.Controls.Add(this.AgreeCB);
            this.Controls.Add(this.SaveBtn);
            this.Controls.Add(this.SubmitBtn);
            this.Controls.Add(this.CancelBtn);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.AmountPeopleTB)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox NameTB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox LastNameTB;
        private System.Windows.Forms.TextBox EmailTB;
        private System.Windows.Forms.MaskedTextBox PhoneTB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown AmountPeopleTB;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox RoomTypeCB;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.MonthCalendar monthCalendar1;
        private System.Windows.Forms.TextBox MessageTB;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button SubmitBtn;
        private System.Windows.Forms.Button CancelBtn;
        private System.Windows.Forms.CheckBox AgreeCB;
        private System.Windows.Forms.Button SaveBtn;
        private System.Windows.Forms.Button LoadBtn;
    }
}

