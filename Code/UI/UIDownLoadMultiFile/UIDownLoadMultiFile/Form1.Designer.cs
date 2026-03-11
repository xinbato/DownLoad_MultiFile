namespace UIDownLoadMultiFile
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            splitContainer1 = new SplitContainer();
            button1 = new Button();
            listView1 = new ListView();
            label1 = new Label();
            panel1 = new Panel();
            label7 = new Label();
            label6 = new Label();
            label5 = new Label();
            label4 = new Label();
            label3 = new Label();
            flowLayoutPanel1 = new FlowLayoutPanel();
            label2 = new Label();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // splitContainer1
            // 
            splitContainer1.Dock = DockStyle.Fill;
            splitContainer1.Location = new Point(0, 0);
            splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            splitContainer1.Panel1.Controls.Add(button1);
            splitContainer1.Panel1.Controls.Add(listView1);
            splitContainer1.Panel1.Controls.Add(label1);
            // 
            // splitContainer1.Panel2
            // 
            splitContainer1.Panel2.Controls.Add(panel1);
            splitContainer1.Panel2.Controls.Add(flowLayoutPanel1);
            splitContainer1.Panel2.Controls.Add(label2);
            splitContainer1.Size = new Size(1055, 592);
            splitContainer1.SplitterDistance = 351;
            splitContainer1.TabIndex = 0;
            // 
            // button1
            // 
            button1.Location = new Point(117, 461);
            button1.Name = "button1";
            button1.Size = new Size(94, 29);
            button1.TabIndex = 2;
            button1.Text = "Làm mới";
            button1.UseVisualStyleBackColor = true;
            // 
            // listView1
            // 
            listView1.Location = new Point(12, 32);
            listView1.Name = "listView1";
            listView1.Size = new Size(318, 377);
            listView1.TabIndex = 1;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.View = View.Details;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(104, 20);
            label1.TabIndex = 0;
            label1.Text = "Danh sách File";
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(128, 255, 255);
            panel1.Controls.Add(label7);
            panel1.Controls.Add(label6);
            panel1.Controls.Add(label5);
            panel1.Controls.Add(label4);
            panel1.Controls.Add(label3);
            panel1.Location = new Point(3, 32);
            panel1.Name = "panel1";
            panel1.Size = new Size(685, 23);
            panel1.TabIndex = 2;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(530, 3);
            label7.Name = "label7";
            label7.Size = new Size(65, 20);
            label7.TabIndex = 4;
            label7.Text = "Ngày tải";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(400, 3);
            label6.Name = "label6";
            label6.Size = new Size(55, 20);
            label6.TabIndex = 3;
            label6.Text = "Tốc độ";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(240, 3);
            label5.Name = "label5";
            label5.Size = new Size(75, 20);
            label5.TabIndex = 2;
            label5.Text = "Trạng thái";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(130, 3);
            label4.Name = "label4";
            label4.Size = new Size(79, 20);
            label4.TabIndex = 1;
            label4.Text = "Kích thước";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(0, 3);
            label3.Name = "label3";
            label3.Size = new Size(58, 20);
            label3.TabIndex = 0;
            label3.Text = "Tên tệp";
            // 
            // flowLayoutPanel1
            // 
            flowLayoutPanel1.AllowDrop = true;
            flowLayoutPanel1.Location = new Point(3, 55);
            flowLayoutPanel1.Name = "flowLayoutPanel1";
            flowLayoutPanel1.Size = new Size(685, 486);
            flowLayoutPanel1.TabIndex = 1;
            flowLayoutPanel1.DragDrop += flowLayoutPanel1_DragDrop;
            flowLayoutPanel1.DragEnter += flowLayoutPanel1_DragEnter;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(3, 9);
            label2.Name = "label2";
            label2.Size = new Size(82, 20);
            label2.TabIndex = 0;
            label2.Text = "Khu vực tải";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1055, 592);
            Controls.Add(splitContainer1);
            Name = "Form1";
            Text = "Form1";
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private SplitContainer splitContainer1;
        private Button button1;
        private ListView listView1;
        private Label label1;
        private FlowLayoutPanel flowLayoutPanel1;
        private Label label2;
        private Panel panel1;
        private Label label4;
        private Label label3;
        private Label label7;
        private Label label6;
        private Label label5;
    }
}
