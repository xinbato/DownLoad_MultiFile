#pragma once

#if defined(_MANAGED) || defined(__cplusplus_cli)

using namespace System;
using namespace System::IO;
using namespace System::Net::Sockets;

namespace CoreLogic {
    public ref class Downloader
    {
    public:
        // Hàm lấy danh sách file từ Server
        static System::Collections::Generic::List<String^>^ GetFileListFromServer(String^ ip, int port)
        {
            auto fileList = gcnew System::Collections::Generic::List<String^>();
            try {
                TcpClient^ client = gcnew TcpClient(ip, port);
                NetworkStream^ stream = client->GetStream();
                StreamWriter^ writer = gcnew StreamWriter(stream);
                BinaryReader^ reader = gcnew BinaryReader(stream);

                // Gửi từ khóa xin danh sách
                writer->WriteLine("GET_LIST");
                writer->Flush();

                // Đọc số lượng file
                int count = reader->ReadInt32();

                // Đọc từng tên file và add vào List
                for (int i = 0; i < count; i++) {
                    fileList->Add(reader->ReadString());
                }

                client->Close();
            }
            catch (Exception^ ex) {
                System::Diagnostics::Debug::WriteLine("[WARN] Server connection failed: " + ex->Message);
            }
            return fileList;
        }
        // 1. HÀM TẢI TCP
        static bool DownloadFileFromTCPServer(String^ ip, int port, String^ fileName, String^ saveFolder, Action<int, String^, String^>^ onProgress)
        {
            try {
                TcpClient^ client = gcnew TcpClient(ip, port);
                NetworkStream^ stream = client->GetStream();
                StreamWriter^ writer = gcnew StreamWriter(stream);
                BinaryReader^ reader = gcnew BinaryReader(stream);

                writer->WriteLine(fileName);
                writer->Flush();

                long long fileSize = reader->ReadInt64();
                if (fileSize == 0) { client->Close(); return false; }

                // Tính kích thước MB
                String^ sizeStr = Math::Round(fileSize / 1024.0 / 1024.0, 2).ToString() + " MB";

                String^ fullSavePath = Path::Combine(saveFolder, fileName);
                FileStream^ fs = gcnew FileStream(fullSavePath, FileMode::Create, FileAccess::Write);
                array<Byte>^ buffer = gcnew array<Byte>(4096);
                int bytesRead;
                long long totalReceived = 0;
                int lastPercent = -1;
                DateTime startTime = DateTime::Now;

                while ((bytesRead = stream->Read(buffer, 0, buffer->Length)) > 0) {
                    fs->Write(buffer, 0, bytesRead);
                    totalReceived += bytesRead;
                    int percent = (int)((totalReceived * 100) / fileSize);
                    percent = Math::Min(percent, 100);

                    if (percent > lastPercent) {
                        lastPercent = percent;
                        TimeSpan elapsed = DateTime::Now - startTime;
                        String^ speedTxt = L"Đang tải...";
                        if (elapsed.TotalSeconds > 0) {
                            double speedMBps = (totalReceived / 1024.0 / 1024.0) / elapsed.TotalSeconds;
                            speedTxt = Math::Round(speedMBps, 2).ToString() + " MB/s";
                        }
                        // GỬI 3 THÔNG SỐ VỀ UI
                        if (onProgress != nullptr) onProgress(percent, speedTxt, sizeStr);
                    }
                }
                fs->Close(); client->Close(); return true;
            }
            catch (Exception^ ex) {
                System::Diagnostics::Debug::WriteLine("Download Error: " + ex->Message);
                return false;
            }
        }

        // 2. HÀM TẢI HTTP
        static bool DownloadFromHttp(String^ url, String^ fileName, String^ saveFolder, Action<int, String^, String^>^ onProgress)
        {
            try {
                System::Net::ServicePointManager::SecurityProtocol = (System::Net::SecurityProtocolType)3072;
                System::Net::HttpWebRequest^ request =
                    (System::Net::HttpWebRequest^)System::Net::WebRequest::Create(url);
                request->AllowAutoRedirect = true;  
                request->Timeout = 5000;
                request->UserAgent = "Mozilla/5.0";

                System::Net::HttpWebResponse^ response = (System::Net::HttpWebResponse^)request->GetResponse();
                long long fileSize = response->ContentLength;

                // Tính kích thước MB
                if (fileSize < 0) fileSize = 0;  
                String^ sizeStr = (fileSize > 0) ?
                    Math::Round(fileSize / 1024.0 / 1024.0, 2).ToString() + " MB" :
                    L"Không xác định";

                String^ fullSavePath = System::IO::Path::Combine(saveFolder, fileName);
                System::IO::Stream^ stream = response->GetResponseStream();
                System::IO::FileStream^ fs = gcnew System::IO::FileStream(fullSavePath, System::IO::FileMode::Create, System::IO::FileAccess::Write);

                array<Byte>^ buffer = gcnew array<Byte>(4096);
                int bytesRead;
                long long totalReceived = 0;
                int lastPercent = -1;
                DateTime startTime = DateTime::Now;

                while ((bytesRead = stream->Read(buffer, 0, buffer->Length)) > 0) {
                    fs->Write(buffer, 0, bytesRead);
                    totalReceived += bytesRead;
                    if (fileSize > 0) {
                        int percent = (int)((totalReceived * 100) / fileSize);
                        percent = Math::Min(percent, 100);
                        if (percent > lastPercent) {
                            lastPercent = percent;
                            TimeSpan elapsed = DateTime::Now - startTime;
                            String^ speedTxt = L"Đang tải...";
                            if (elapsed.TotalSeconds > 0) {
                                double speedMBps = (totalReceived / 1024.0 / 1024.0) / elapsed.TotalSeconds;
                                speedTxt = Math::Round(speedMBps, 2).ToString() + " MB/s";
                            }
                            // GỬI 3 THÔNG SỐ VỀ UI
                            if (onProgress != nullptr) onProgress(percent, speedTxt, sizeStr);
                        }
                    }
                }
                fs->Close(); stream->Close(); response->Close(); return true;
            }
            catch (Exception^ ex) {
                System::Diagnostics::Debug::WriteLine("Download Error: " + ex->Message);
                return false;
            }
        }
    };
}

#else 

// If the file is included in a native (non-/clr) compile unit, provide a lightweight native stub
namespace CoreLogic {
    struct Downloader {
        // Simple stub to allow native projects to compile when they include this header.
        // It intentionally does nothing and returns false.
        static bool DownloadFileFromTCPServer(const char* /*ip*/, int /*port*/, const char* /*fileName*/, const char* /*saveFolder*/) { return false; }
    };
}

#endif 
