namespace UIDownLoadMultiFile
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void flowLayoutPanel1_DragEnter(object sender, DragEventArgs e)
        {
            // Kiểm tra xem thứ người dùng đang kéo vào có phải là File không?
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy; // Đổi con trỏ chuột thành dấu + (Báo hiệu cho phép thả)
            }
            else
            {
                e.Effect = DragDropEffects.None; // Trỏ chuột hiện dấu cấm (Nếu kéo linh tinh vào)
            }
        }

        private void flowLayoutPanel1_DragDrop(object sender, DragEventArgs e)
        {
            // Thêm dấu ? và ! để báo với C# rằng mình đã kiểm soát vụ dữ liệu rỗng (hết báo vàng)
            string[]? files = (string[]?)e.Data!.GetData(DataFormats.FileDrop);

            // Nếu không có file nào được kéo vào thì thoát luôn không làm gì cả
            if (files == null) return;

            foreach (string filePath in files)
            {
                // 1. Dùng class FileInfo để lấy toàn bộ thông tin gốc của file
                System.IO.FileInfo fileInfo = new System.IO.FileInfo(filePath);

                // 2. Lấy Tên file
                string fileName = fileInfo.Name;

                // 3. Lấy Kích thước file (Quy đổi từ Byte sang MB và làm tròn 2 chữ số)
                double sizeInMB = fileInfo.Length / (1024.0 * 1024.0);
                string fileSize = Math.Round(sizeInMB, 2) + " MB";

                // 4. Lấy Ngày tháng hiện tại
                string date = DateTime.Now.ToString("dd/MM/yyyy");

                // 5. Đúc ra cái khuôn giao diện bạn vừa thiết kế
                DownloadItemControl downloadItem = new DownloadItemControl();

                // 6. TRUYỀN ĐỦ 3 THÔNG TIN vào khuôn (Khắc phục lỗi đỏ CS7036)
                downloadItem.SetupInfo(fileName, fileSize, date);

                // 7. Nhét cái khuôn này vào FlowLayoutPanel trên màn hình
                flowLayoutPanel1.Controls.Add(downloadItem);
            }
        }
    }
}
