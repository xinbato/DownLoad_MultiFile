# 🚀 Multi-File Downloader (C++/CLI)

Một ứng dụng quản lý tải xuống nhiều tệp tin cùng lúc với giao diện hiện đại, tối ưu hóa trải nghiệm người dùng trên nền tảng **Windows Forms**.

---

### ✨ Tính năng nổi bật

* **🖱️ Drag & Drop:** Kéo thả tệp tin trực tiếp từ Windows Explorer vào ứng dụng để chuẩn bị tải.
* **🗂️ Giao diện Card UI:** Thiết kế các thẻ (Cards) riêng biệt, giúp danh sách tệp tin rõ ràng, dễ nhìn.
* **📊 Thông tin thời gian thực:** Hiển thị chi tiết Tên tệp, Kích thước, Tốc độ, Trạng thái và Ngày thêm.
* **✨ Hiệu ứng Tương tác:** Giao diện phản hồi mượt mà (Hover effect) khi di chuyển chuột qua các mục.
* **⚙️ Quản lý luồng động:** Sử dụng `FlowLayoutPanel` để tự động sắp xếp danh sách tệp tin không giới hạn.

---

### 🛠 Công nghệ & Công cụ sử dụng

| Thành phần | Chi tiết công nghệ |
| :--- | :--- |
| **Ngôn ngữ lập trình** | C++/CLI (Visual C++) |
| **Framework** | .NET Framework (Windows Forms) |
| **Môi trường phát triển** | Visual Studio 2022 |
| **Kiến trúc** | Custom UserControl & Event-driven Programming |

---

### 📂 Cấu trúc dự án chính

> [!TIP]
> Dự án được thiết kế theo hướng module hóa để dễ dàng nâng cấp logic tải xuống sau này.

* **`Form1.h`**: Điều khiển luồng chính, xử lý sự kiện kéo thả và quản lý danh sách.
* **`DownloadItemControl.h`**: Thành phần UI tùy chỉnh cho từng dòng tệp tin (giữ layout xanh Cyan đặc trưng).
* **`Core/Coredownload/`**: Thư viện xử lý logic kết nối và tải dữ liệu xuống máy tính.

---

### 🚀 Hướng dẫn chạy thử

1. Mở file `.sln` bằng **Visual Studio 2022**.
2. Đảm bảo đã cài đặt package **Desktop development with C++** và **C++/CLI support**.
3. Nhấn `F5` để biên dịch và chạy ứng dụng.

---  
**📅 Cập nhật lần cuối:** 10/04/2026  
**🏫 Đồ án:** Lập trình mạng / Windows Programming.
