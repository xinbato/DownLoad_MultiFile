#pragma once
#include "Coredownload.h"
#include "DownloadItemControl.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label7;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(15, 28);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(320, 447);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Danh sách File";
			// 
			// panel1
			// 
			this->panel1->AllowDrop = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(6, 28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(692, 26);
			this->panel1->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(530, 10);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 16);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Ngày tải";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(250, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Tốc độ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(400, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Trạng thái";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(130, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Kích thước";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(-3, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Tên tệp";
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
};
}
