namespace UIDownLoadMultiFile
{
    partial class DownloadItemControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            lblFileName = new Label();
            lblSize = new Label();
            progressBarDownload = new ProgressBar();
            lblPercent = new Label();
            lblSpeed = new Label();
            lblDate = new Label();
            btnCancel = new Button();
            SuspendLayout();
            // 
            // lblFileName
            // 
            lblFileName.AutoSize = true;
            lblFileName.Location = new Point(3, 10);
            lblFileName.Name = "lblFileName";
            lblFileName.Size = new Size(50, 20);
            lblFileName.TabIndex = 0;
            lblFileName.Text = "label1";
            // 
            // lblSize
            // 
            lblSize.AutoSize = true;
            lblSize.Location = new Point(130, 10);
            lblSize.Name = "lblSize";
            lblSize.Size = new Size(50, 20);
            lblSize.TabIndex = 1;
            lblSize.Text = "label1";
            // 
            // progressBarDownload
            // 
            progressBarDownload.Location = new Point(240, 10);
            progressBarDownload.Name = "progressBarDownload";
            progressBarDownload.Size = new Size(77, 20);
            progressBarDownload.TabIndex = 2;
            // 
            // lblPercent
            // 
            lblPercent.AutoSize = true;
            lblPercent.Location = new Point(323, 10);
            lblPercent.Name = "lblPercent";
            lblPercent.Size = new Size(50, 20);
            lblPercent.TabIndex = 3;
            lblPercent.Text = "label1";
            // 
            // lblSpeed
            // 
            lblSpeed.AutoSize = true;
            lblSpeed.Location = new Point(400, 10);
            lblSpeed.Name = "lblSpeed";
            lblSpeed.Size = new Size(50, 20);
            lblSpeed.TabIndex = 4;
            lblSpeed.Text = "label1";
            // 
            // lblDate
            // 
            lblDate.AutoSize = true;
            lblDate.Location = new Point(530, 10);
            lblDate.Name = "lblDate";
            lblDate.Size = new Size(50, 20);
            lblDate.TabIndex = 5;
            lblDate.Text = "label1";
            // 
            // btnCancel
            // 
            btnCancel.BackColor = Color.FromArgb(192, 0, 0);
            btnCancel.ForeColor = Color.Red;
            btnCancel.Location = new Point(640, 6);
            btnCancel.Name = "btnCancel";
            btnCancel.Size = new Size(27, 29);
            btnCancel.TabIndex = 6;
            btnCancel.Text = "X";
            btnCancel.UseVisualStyleBackColor = false;
            // 
            // DownloadItemControl
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(224, 224, 224);
            Controls.Add(btnCancel);
            Controls.Add(lblDate);
            Controls.Add(lblSpeed);
            Controls.Add(lblPercent);
            Controls.Add(progressBarDownload);
            Controls.Add(lblSize);
            Controls.Add(lblFileName);
            Name = "DownloadItemControl";
            Size = new Size(685, 40);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblFileName;
        private Label lblSize;
        private ProgressBar progressBarDownload;
        private Label lblPercent;
        private Label lblSpeed;
        private Label lblDate;
        private Button btnCancel;
    }
}
