#pragma once
#include "..\\..\\..\\Core\\Coredownload\\Coredownload.h"
#include "DownloadItemControl.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Threading;
	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			// Đăng ký sự kiện MouseDown cho listBoxFiles bằng code 
			this->listBoxFiles->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::listBoxFiles_MouseDown);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ nameFile;
	private: System::Windows::Forms::Label^ speedFile;
	private: System::Windows::Forms::Label^ statusFile;
	private: System::Windows::Forms::Label^ sizeFile;
	private: System::Windows::Forms::Label^ dayFile;
	private: System::ComponentModel::IContainer^ components;

	
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ btnRefresh_Click;
	private: System::Windows::Forms::ListBox^ listBoxFiles;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolTip^ toolTip2;

		   System::Drawing::Font^ headerFont = gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Bold);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
			this->btnRefresh_Click = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dayFile = (gcnew System::Windows::Forms::Label());
			this->speedFile = (gcnew System::Windows::Forms::Label());
			this->statusFile = (gcnew System::Windows::Forms::Label());
			this->sizeFile = (gcnew System::Windows::Forms::Label());
			this->nameFile = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->listBoxFiles);
			this->splitContainer1->Panel1->Controls->Add(this->btnRefresh_Click);
			this->splitContainer1->Panel1->Controls->Add(this->checkedListBox1);
			this->splitContainer1->Panel1->Controls->Add(this->listView1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->panel1);
			this->splitContainer1->Panel2->Controls->Add(this->flowLayoutPanel1);
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Size = System::Drawing::Size(1070, 625);
			this->splitContainer1->SplitterDistance = 356;
			this->splitContainer1->TabIndex = 0;
			// 
			// listBoxFiles
			// 
			this->listBoxFiles->FormattingEnabled = true;
			this->listBoxFiles->ItemHeight = 16;
			this->listBoxFiles->Location = System::Drawing::Point(16, 38);
			this->listBoxFiles->Name = L"listBoxFiles";
			this->listBoxFiles->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBoxFiles->Size = System::Drawing::Size(320, 452);
			this->listBoxFiles->TabIndex = 6;
			this->listBoxFiles->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBoxFiles_SelectedIndexChanged);
			// 
			// btnRefresh_Click
			// 
			this->btnRefresh_Click->Location = System::Drawing::Point(131, 531);
			this->btnRefresh_Click->Name = L"btnRefresh_Click";
			this->btnRefresh_Click->Size = System::Drawing::Size(75, 23);
			this->btnRefresh_Click->TabIndex = 5;
			this->btnRefresh_Click->Text = L"Làm mới";
			this->btnRefresh_Click->UseVisualStyleBackColor = true;
			this->btnRefresh_Click->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->Location = System::Drawing::Point(69, 85);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(120, 89);
			this->checkedListBox1->TabIndex = 7;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox1_SelectedIndexChanged);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::White;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(16, 43);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(320, 447);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Danh sách File";
			// 
			// panel1
			// 
			this->panel1->AllowDrop = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->dayFile);
			this->panel1->Controls->Add(this->speedFile);
			this->panel1->Controls->Add(this->statusFile);
			this->panel1->Controls->Add(this->sizeFile);
			this->panel1->Controls->Add(this->nameFile);
			this->panel1->ForeColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(6, 28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(692, 26);
			this->panel1->TabIndex = 2;
			// 
			// dayFile
			// 
			this->dayFile->AutoSize = true;
			this->dayFile->ForeColor = System::Drawing::Color::Black;
			this->dayFile->Location = System::Drawing::Point(530, 10);
			this->dayFile->Name = L"dayFile";
			this->dayFile->Size = System::Drawing::Size(57, 16);
			this->dayFile->TabIndex = 4;
			this->dayFile->Text = L"Ngày tải";
			this->dayFile->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// speedFile
			// 
			this->speedFile->AutoSize = true;
			this->speedFile->ForeColor = System::Drawing::Color::Black;
			this->speedFile->Location = System::Drawing::Point(250, 10);
			this->speedFile->Name = L"speedFile";
			this->speedFile->Size = System::Drawing::Size(50, 16);
			this->speedFile->TabIndex = 3;
			this->speedFile->Text = L"Tốc độ";
			// 
			// statusFile
			// 
			this->statusFile->AutoSize = true;
			this->statusFile->ForeColor = System::Drawing::Color::Black;
			this->statusFile->Location = System::Drawing::Point(377, 10);
			this->statusFile->Name = L"statusFile";
			this->statusFile->Size = System::Drawing::Size(67, 16);
			this->statusFile->TabIndex = 2;
			this->statusFile->Text = L"Trạng thái";
			this->statusFile->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// sizeFile
			// 
			this->sizeFile->AutoSize = true;
			this->sizeFile->ForeColor = System::Drawing::Color::Black;
			this->sizeFile->Location = System::Drawing::Point(130, 10);
			this->sizeFile->Name = L"sizeFile";
			this->sizeFile->Size = System::Drawing::Size(67, 16);
			this->sizeFile->TabIndex = 1;
			this->sizeFile->Text = L"Kích thước";
			// 
			// nameFile
			// 
			this->nameFile->AutoSize = true;
			this->nameFile->ForeColor = System::Drawing::Color::Black;
			this->nameFile->Location = System::Drawing::Point(-3, 10);
			this->nameFile->Name = L"nameFile";
			this->nameFile->Size = System::Drawing::Size(53, 16);
			this->nameFile->TabIndex = 0;
			this->nameFile->Text = L"Tên tệp";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AllowDrop = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(6, 60);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(692, 553);
			this->flowLayoutPanel1->TabIndex = 1;
			this->flowLayoutPanel1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::flowLayoutPanel1_DragDrop);
			this->flowLayoutPanel1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::flowLayoutPanel1_DragEnter);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(3, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Khu vực tải";
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->toolTip1->ToolTipTitle = L"Thông báo hệ thống";
			// 
			// toolTip2
			// 
			this->toolTip2->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->toolTip2->ToolTipTitle = L"Cảnh báo hệ thống";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->ClientSize = System::Drawing::Size(1070, 625);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"DownLoadMultiFile";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
 // SỰ KIỆN NẮM FILE (KÉO TỪ LIST BÊN TRÁI)
private: System::Void listBoxFiles_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Chỉ bắt đầu kéo nếu người dùng chọn bằng chuột trái và có ít nhất 1 file được bôi đen
		if (listBoxFiles->SelectedItems->Count == 0 || e->Button != System::Windows::Forms::MouseButtons::Left) return;

		// Gom toàn bộ file được chọn vào mảng
		array<String^>^ selectedFiles = gcnew array<String^>(listBoxFiles->SelectedItems->Count);
		for (int i = 0; i < listBoxFiles->SelectedItems->Count; i++) {
			selectedFiles[i] = listBoxFiles->SelectedItems[i]->ToString();
		}

		// Tạo gói hàng tên "ServerFiles" để ném sang bảng bên kia
		System::Windows::Forms::DataObject^ dragData = gcnew System::Windows::Forms::DataObject("ServerFiles", selectedFiles);
		listBoxFiles->DoDragDrop(dragData, System::Windows::Forms::DragDropEffects::Copy);
}

 // SỰ KIỆN LƯỚT CHUỘT QUA Ô TẢI

	private: System::Void flowLayoutPanel1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		// Nhận gói hàng Server ("ServerFiles") HOẶC link web (Text)
		if (e->Data->GetDataPresent("ServerFiles") ||
			e->Data->GetDataPresent(System::Windows::Forms::DataFormats::Text)) {
			e->Effect = System::Windows::Forms::DragDropEffects::Copy;
		}
		else {
			e->Effect = System::Windows::Forms::DragDropEffects::None;
		}
	}

 // SỰ KIỆN THẢ CHUỘT ĐỂ BẮT ĐẦU TẢI

private: System::Void flowLayoutPanel1_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	String^ saveFolder = "D:\\Downloads\\"; // Thư mục lưu file

	// =========================================================
	// TRƯỜNG HỢP 1: THẢ FILE TỪ DANH SÁCH BÊN TRÁI (TẢI TCP LOCAL)
	// =========================================================
	if (e->Data->GetDataPresent("ServerFiles")) {
		array<String^>^ files = (array<String^>^)e->Data->GetData("ServerFiles");

		for each (String ^ fileName in files) {
			UIdownLoad::DownloadItemControl^ downloadItem = gcnew UIdownLoad::DownloadItemControl();
			downloadItem->SetupInfo(fileName,"", System::DateTime::Now.ToString("dd/MM/yyyy HH:mm"));
			flowLayoutPanel1->Controls->Add(downloadItem);

			System::Threading::Thread^ downloadThread = gcnew System::Threading::Thread(
				gcnew System::Threading::ParameterizedThreadStart(this, &Form1::DownloadTask)
			);
			array<System::Object^>^ args = gcnew array<System::Object^>(3);
			args[0] = fileName;
			args[1] = saveFolder;
			args[2] = downloadItem;
			downloadThread->Start(args);
		}
	}
	// =========================================================
		// TRƯỜNG HỢP 2: THẢ LINK TỪ WEB/NOTEPAD VÀO (HỖ TRỢ MULTI-LINK)
		// =========================================================
	else if (e->Data->GetDataPresent(System::Windows::Forms::DataFormats::Text)) {
		String^ draggedText = e->Data->GetData(System::Windows::Forms::DataFormats::Text)->ToString();

		// Tuyệt chiêu băm chuỗi: Tách các link ra dựa vào dấu xuống dòng
		array<String^>^ links = draggedText->Split(
			gcnew array<System::Char>{'\n', '\r'},
			System::StringSplitOptions::RemoveEmptyEntries
		);

		for each (String ^ rawLink in links) {
			String^ url = rawLink->Trim();
			if (String::IsNullOrEmpty(url)) continue;

			// Chỉ xử lý nếu là link web chuẩn
			if (url->StartsWith("http://") || url->StartsWith("https://")) {
				String^ fileName = "";
				try {
					Uri^ uri = gcnew Uri(url);
					// Lấy nguyên gốc tên file từ URL và giải mã các ký tự web (ví dụ %20 thành dấu cách)
					fileName = System::Uri::UnescapeDataString(System::IO::Path::GetFileName(uri->LocalPath));
				}
				catch (...) {}

				// CHỈ TỰ ĐẶT TÊN NẾU LINK CỤT LỦN (Ví dụ kéo cái link trang chủ https://google.com/)
				if (String::IsNullOrWhiteSpace(fileName) || fileName == "/") {
					fileName = "Tap_Tin_Web_" + System::DateTime::Now.ToString("HHmmss");
				}

				// Tạo giao diện thanh tải
				UIdownLoad::DownloadItemControl^ downloadItem = gcnew UIdownLoad::DownloadItemControl();
				downloadItem->SetupInfo(fileName,"", System::DateTime::Now.ToString("dd/MM/yyyy HH:mm"));
				flowLayoutPanel1->Controls->Add(downloadItem);

				// Khởi tạo luồng tải ngầm cho link HTTP này
				System::Threading::Thread^ downloadThread = gcnew System::Threading::Thread(
					gcnew System::Threading::ParameterizedThreadStart(this, &Form1::DownloadHttpTask)
				);

				array<System::Object^>^ args = gcnew array<System::Object^>(4);
				args[0] = url;
				args[1] = saveFolder;
				args[2] = downloadItem;
				args[3] = fileName;
				downloadThread->Start(args);
			}
			else {
				MessageBox::Show(L"URL không hợp lệ! Vui lòng kéo link HTTP/HTTPS.");
			}
		}
	}
}


				   // LUỒNG TẢI TỪ SERVER LOCAL (TCP)
				
	private: void DownloadTask(System::Object^ obj) {
		array<System::Object^>^ args = (array<System::Object^>^)obj;
		String^ fileName = (String^)args[0];
		String^ saveFolder = (String^)args[1];
		UIdownLoad::DownloadItemControl^ itemControl = (UIdownLoad::DownloadItemControl^)args[2];

		String^ ip = "127.0.0.1";
		int port = 9000;

		System::Action<int, String^, String^>^ progressCallback = gcnew System::Action<int, String^, String^>(itemControl, &UIdownLoad::DownloadItemControl::UpdateProgress);
		bool success = CoreLogic::Downloader::DownloadFileFromTCPServer(ip, port, fileName, saveFolder, progressCallback);

		this->Invoke(gcnew System::Action<bool, UIdownLoad::DownloadItemControl^>(this, &Form1::UpdateUI), success, itemControl);
	}

		   // ==========================================
		   // LUỒNG TẢI TỪ INTERNET (HTTP)
		   // ==========================================
private: void DownloadHttpTask(System::Object^ obj) {
		array<System::Object^>^ args = (array<System::Object^>^)obj;
		String^ url = (String^)args[0];
		String^ saveFolder = (String^)args[1];
		UIdownLoad::DownloadItemControl^ itemControl = (UIdownLoad::DownloadItemControl^)args[2];

		String^ fileName;
		if (args->Length > 3 && args[3] != nullptr) {
			fileName = (String^)args[3];
		}
		else {
			fileName = "downloaded_file.dat";
		}

		System::Action<int, String^, String^>^ progressCallback = gcnew System::Action<int, String^, String^>(itemControl, &UIdownLoad::DownloadItemControl::UpdateProgress);
		bool success = CoreLogic::Downloader::DownloadFromHttp(url, fileName, saveFolder, progressCallback);

		this->Invoke(gcnew System::Action<bool, UIdownLoad::DownloadItemControl^>(this, &Form1::UpdateUI), success, itemControl);
	}
		// ==========================================
		// CẬP NHẬT UI KHI TẢI XONG
		// ==========================================
	private: void UpdateUI(bool success, UIdownLoad::DownloadItemControl^ itemControl) {
		if (success) {
			System::Drawing::Point mousePos = System::Windows::Forms::Cursor::Position;
			toolTip1->Show(L"File đã được tải xong!", this, mousePos.X, mousePos.Y, 3000);
			btnRefresh_Click->Enabled = true;
		}
		else {
			System::Drawing::Point mousePos = System::Windows::Forms::Cursor::Position;
			toolTip2->Show(L"File tải thất bại!", this,mousePos.X,mousePos.Y, 3000);
			btnRefresh_Click->Enabled=true;
		}
	}
			// ==========================================
		   // NUT LAM MOI DANH SACH TU SERVER
		   // ==========================================
				
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ip = "127.0.0.1";
	int port = 9000;
	// Xóa danh sách listBoxFiles cũ
	listBoxFiles->Items->Clear();
	auto files = CoreLogic::Downloader::GetFileListFromServer(ip, port);
	if (files->Count == 0) {
		MessageBox::Show(L"Server không có file nào hoặc mất kết nối!");
		return;
	}
	// Đổ dữ liệu vào listBoxFiles
	for each(String ^ fileName in files) {
		listBoxFiles->Items->Add(fileName);
		btnRefresh_Click->Enabled=false;
	}
}
	// Các sự kiện UI nhỏ nhặt giữ nguyên
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void DownloadItem_MouseEnter(System::Object^ sender, System::EventArgs^ e) { this->BackColor = System::Drawing::Color::AliceBlue; }
	private: System::Void DownloadItem_MouseLeave(System::Object^ sender, System::EventArgs^ e) { this->BackColor = System::Drawing::Color::White; }
	private: System::Void listBoxFiles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void btnDownload_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
