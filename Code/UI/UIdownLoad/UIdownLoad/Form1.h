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
			// Đăng ký sự kiện MouseDown cho listBoxFiles bằng code (phòng khi bạn chưa bấm ở giao diện)
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
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ btnDownload;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ btnRefresh_Click;
	private: System::Windows::Forms::ListBox^ listBoxFiles;

		   System::Drawing::Font^ headerFont = gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Bold);



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Drawing::Font^ headerFont = gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Bold);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->btnRefresh_Click = (gcnew System::Windows::Forms::Button());
			this->btnDownload = (gcnew System::Windows::Forms::Button());
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
			this->splitContainer1->Panel1->Controls->Add(this->btnDownload);
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
			this->listBoxFiles->Location = System::Drawing::Point(16, 28);
			this->listBoxFiles->Name = L"listBoxFiles";
			this->listBoxFiles->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBoxFiles->Size = System::Drawing::Size(320, 452);
			this->listBoxFiles->TabIndex = 6;
			this->listBoxFiles->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBoxFiles_SelectedIndexChanged);
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->BackColor = System::Drawing::Color::White;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listView1->Location = System::Drawing::Point(15, 28);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(320, 447);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// btnRefresh_Click
			// 
			this->btnRefresh_Click->Location = System::Drawing::Point(256, 0);
			this->btnRefresh_Click->Name = L"btnRefresh_Click";
			this->btnRefresh_Click->Size = System::Drawing::Size(75, 23);
			this->btnRefresh_Click->TabIndex = 5;
			this->btnRefresh_Click->Text = L"Làm mới";
			this->btnRefresh_Click->UseVisualStyleBackColor = true;
			this->btnRefresh_Click->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = headerFont;
			this->label1->Font = gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);
			
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Danh sách File";
			// 
			// panel1
			// 
			this->panel1->AllowDrop = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(192, 255, 255);
			this->panel1->ForeColor = System::Drawing::Color::Black;
			this->panel1->Height = 35;
			this->panel1->Controls->Add(this->dayFile);
			this->panel1->Controls->Add(this->speedFile);
			this->panel1->Controls->Add(this->statusFile);
			this->panel1->Controls->Add(this->sizeFile);
			this->panel1->Controls->Add(this->nameFile);
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
			this->statusFile->Location = System::Drawing::Point(400, 10);
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
			this->label2->Location = System::Drawing::Point(3, 9);
			this->label2->Font = headerFont;
			this->label2->Font = gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Khu vực tải";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
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
#pragma endregion
	private: System::Void flowLayoutPanel1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		// Kiểm tra xem có phải người dùng đang kéo File vào không
		if (e->Data->GetDataPresent(System::Windows::Forms::DataFormats::FileDrop)) {
			e->Effect = System::Windows::Forms::DragDropEffects::Copy; // Bật biểu tượng dấu +
		}
		else {
			e->Effect = System::Windows::Forms::DragDropEffects::None; // Bật biểu tượng cấm
		}
	}
private: System::Void flowLayoutPanel1_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	// Ép kiểu lấy danh sách đường dẫn file
	array<System::String^>^ files = safe_cast<array<System::String^>^>(e->Data->GetData(System::Windows::Forms::DataFormats::FileDrop));

	if (files == nullptr) return;

	// Duyệt qua từng file được thả vào
	for each (System::String ^ filePath in files) {

		System::IO::FileInfo^ fileInfo = gcnew System::IO::FileInfo(filePath);

		System::String^ fileName = fileInfo->Name;

		// Tính dung lượng file ra MB
		double sizeInMB = fileInfo->Length / (1024.0 * 1024.0);
		System::String^ fileSize = System::Math::Round(sizeInMB, 2).ToString() + " MB";

		// Lấy ngày tháng hiện tại
		System::String^ date = System::DateTime::Now.ToString("dd/MM/yyyy");

		// Gọi cái khuôn giao diện ra (Nhớ thay UIdownLoad bằng namespace của bạn nếu báo lỗi đỏ)
		UIdownLoad::DownloadItemControl^ downloadItem = gcnew UIdownLoad::DownloadItemControl();

		// Truyền dữ liệu vào
		downloadItem->SetupInfo(fileName, fileSize, date);

		// Nhét vào bảng hiển thị
		flowLayoutPanel1->Controls->Add(downloadItem);
	}
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DownloadItem_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	this->BackColor = System::Drawing::Color::AliceBlue;
}
private: System::Void DownloadItem_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->BackColor = System::Drawing::Color::White;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ip = "127.0.0.1";
	int port = 9000;
	// Xóa danh sách listBoxFiles cũ
	listBoxFiles->Items->Clear();
	auto files = CoreLogic::Downloader::GetFileListFromServer(ip, port);
	if (files->Count == 0) {
		MessageBox::Show("Server không có file nào hoặc mất kết nối!");
		return;
	}
	// Đổ dữ liệu vào listBoxFiles
	for each(String ^ fileName in files) {
		listBoxFiles->Items->Add(fileName);
	}
}
};
}
