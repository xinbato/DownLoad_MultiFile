#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UIdownLoad {

	/// <summary>
	/// Summary for DownloadItemControl
	/// </summary>
	public ref class DownloadItemControl : public System::Windows::Forms::UserControl
	{
	public:
		DownloadItemControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		// Hàm nhận dữ liệu truyền vào từ Form chính
	void SetupInfo(System::String^ fileName, System::String^ fileSize, System::String^ date)
		{
			// Gán dữ liệu lên các Label (Dùng đúng tên biến bạn đang có ở dòng 38-45)
			lblName->Text = fileName;
			lblSize->Text = fileSize;
			lblDate->Text = date;

			progressBar1->Value = 0;
			lblPercent->Text = "0%";
			lblSpeed->Text = "Loading...";
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DownloadItemControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblName;
	protected:
	private: System::Windows::Forms::Label^ lblSize;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ lblPercent;

	private: System::Windows::Forms::Label^ lblDate;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lblSpeed;



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
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblSize = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->lblPercent = (gcnew System::Windows::Forms::Label());
			this->lblDate = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblSpeed = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblName
			// 
			this->lblName->Location = System::Drawing::Point(0, 15);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(97, 16);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"label1";
			// 
			// lblSize
			// 
			this->lblSize->AutoSize = true;
			this->lblSize->Location = System::Drawing::Point(130, 15);
			this->lblSize->Name = L"lblSize";
			this->lblSize->Size = System::Drawing::Size(44, 16);
			this->lblSize->TabIndex = 1;
			this->lblSize->Text = L"label1";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(251, 11);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(74, 23);
			this->progressBar1->TabIndex = 2;
			// 
			// lblPercent
			// 
			this->lblPercent->AutoSize = true;
			this->lblPercent->Location = System::Drawing::Point(331, 15);
			this->lblPercent->Name = L"lblPercent";
			this->lblPercent->Size = System::Drawing::Size(44, 16);
			this->lblPercent->TabIndex = 3;
			this->lblPercent->Text = L"label1";
			this->lblPercent->Click += gcnew System::EventHandler(this, &DownloadItemControl::lblPercent_Click);
			// 
			// lblDate
			// 
			this->lblDate->AutoSize = true;
			this->lblDate->Location = System::Drawing::Point(530, 15);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(44, 16);
			this->lblDate->TabIndex = 5;
			this->lblDate->Text = L"label1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(650, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(37, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &DownloadItemControl::button1_Click);
			// 
			// lblSpeed
			// 
			this->lblSpeed->AutoSize = true;
			this->lblSpeed->Location = System::Drawing::Point(400, 15);
			this->lblSpeed->Name = L"lblSpeed";
			this->lblSpeed->Size = System::Drawing::Size(44, 16);
			this->lblSpeed->TabIndex = 7;
			this->lblSpeed->Text = L"label1";
			// 
			// DownloadItemControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->lblSpeed);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblDate);
			this->Controls->Add(this->lblPercent);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->lblSize);
			this->Controls->Add(this->lblName);
			this->Name = L"DownloadItemControl";
			this->Size = System::Drawing::Size(690, 50);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lblPercent_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: void UpdateProgress(int percent, System::String^ speedTxt) {
	// Phải kiểm tra InvokeRequired vì hàm này bị gọi từ luồng ngầm (Core)
	if (this->InvokeRequired) {
		this->Invoke(gcnew System::Action<int, System::String^>(this, &DownloadItemControl::UpdateProgress), percent, speedTxt);
		return;
	}
	// Cập nhật giao diện
	this->progressBar1->Value = percent;
	this->lblPercent->Text = percent.ToString() + "%";
	this->lblSpeed->Text = speedTxt;
}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->Parent != nullptr) {
			this->Parent->Controls->Remove(this);
		}
	}
};
}
