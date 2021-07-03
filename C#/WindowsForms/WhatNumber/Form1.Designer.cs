
namespace WhatNumber
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.PushMeBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // PushMeBtn
            // 
            this.PushMeBtn.Location = new System.Drawing.Point(180, 78);
            this.PushMeBtn.Name = "PushMeBtn";
            this.PushMeBtn.Size = new System.Drawing.Size(75, 37);
            this.PushMeBtn.TabIndex = 0;
            this.PushMeBtn.Text = "Push me";
            this.PushMeBtn.UseVisualStyleBackColor = true;
            this.PushMeBtn.Click += new System.EventHandler(this.PushMe_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(438, 215);
            this.Controls.Add(this.PushMeBtn);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "What number?";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button PushMeBtn;
    }
}

