using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace UIDownLoadMultiFile
{
    public partial class DownloadItemControl : UserControl
    {
        public DownloadItemControl()
        {
            InitializeComponent();
        }

        // Hàm này để Form chính gọi 1 lần duy nhất khi vừa thả file vào
        public void SetupInfo(string fileName, string fileSize, string date)
        {
            lblFileName.Text = fileName;
            lblSize.Text = fileSize;     // Gán kích thước (VD: "15.5 MB")
            lblDate.Text = date;         // Gán ngày tải (VD: "09/03/2026")
            progressBarDownload.Value = 0;
            lblPercent.Text = "0%";
            lblSpeed.Text = "Đang kết nối...";
        }

        // Hàm này Form chính sẽ gọi liên tục mỗi giây để cập nhật % và tốc độ
        public void UpdateProgress(int percent, string speedInfo)
        {
            // Đảm bảo phần trăm không vượt quá 100 bị lỗi
            if (percent >= 0 && percent <= 100)
            {
                progressBarDownload.Value = percent;
            }
            lblPercent.Text = percent.ToString() + "%";
            lblSpeed.Text = speedInfo;
        }
    }
}
