DownLoad_MultiFile
Multi-File Downloader (C++/CLI)
Ứng dụng hỗ trợ tải xuống nhiều tệp tin cùng lúc với giao diện hiện đại, được xây dựng bằng ngôn ngữ C++/CLI trên nền tảng Windows Forms.

Tính năng nổi bật
Drag & Drop: Kéo thả tệp tin trực tiếp từ Windows Explorer vào ứng dụng để chuẩn bị tải.

Giao diện Card UI: Thiết kế hiện đại với các thẻ (Cards) riêng biệt cho từng tệp tin.

Thông tin chi tiết: Hiển thị Tên tệp, Kích thước, Tốc độ, Trạng thái và Ngày thêm tệp.

Hiệu ứng Hover: Giao diện phản hồi mượt mà khi di chuột qua các mục danh sách.

Quản lý luồng: Hỗ trợ xử lý danh sách tệp tin động qua FlowLayoutPanel.

Công nghệ sử dụng
Ngôn ngữ: C++/CLI (Visual C++)

Framework: .NET Framework (Windows Forms)

Công cụ: Visual Studio 2022

Thành phần chính: * SplitContainer: Chia đôi màn hình quản lý.

Custom UserControl: DownloadItemControl để hiển thị từng dòng tải xuống.

DragDrop Events: Xử lý tương tác kéo thả.

Giao diện ứng dụng
Hướng dẫn: Bạn có thể chụp ảnh màn hình ứng dụng và lưu vào thư mục images, sau đó thay link dưới đây.

Hướng dẫn cài đặt & Chạy
Yêu cầu: Đã cài đặt Visual Studio (có gói Desktop development with C++ và C++/CLI support).

Clone dự án:

Bash
git clone https://github.com/xinbato/DownLoad_MultiFile
Mở Project: Mở file .sln bằng Visual Studio.

Build & Run: Nhấn F5 hoặc nút Start để biên dịch và trải nghiệm.

Cấu trúc thư mục chính
Form1.h: Luồng xử lý chính và giao diện tổng thể.

DownloadItemControl.h: Thành phần giao diện tùy chỉnh cho từng tệp tin.

Core/: Chứa các thư viện xử lý logic tải xuống (Coredownload).