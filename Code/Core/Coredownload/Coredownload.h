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
            catch (Exception^) {}

            return fileList;
        }
        // Original method with progress callback
        static bool DownloadFileFromTCPServer(String^ ip, int port, String^ fileName, String^ saveFolder, Action<int, String^>^ onProgress)
        {
            try {
                TcpClient^ client = gcnew TcpClient(ip, port);
                NetworkStream^ stream = client->GetStream();
                StreamWriter^ writer = gcnew StreamWriter(stream);
                BinaryReader^ reader = gcnew BinaryReader(stream);

                writer->WriteLine(fileName);
                writer->Flush();

                long long fileSize = reader->ReadInt64();
                if (fileSize == 0) {
                    client->Close(); return false;
                }

                String^ fullSavePath = Path::Combine(saveFolder, fileName);
                FileStream^ fs = gcnew FileStream(fullSavePath, FileMode::Create, FileAccess::Write);

                array<Byte>^ buffer = gcnew array<Byte>(4096);
                int bytesRead;
                long long totalReceived = 0;

              
                int lastPercent = -1;
                // Bắt đầu tính giờ để đo tốc độ
                DateTime startTime = DateTime::Now;

                while (totalReceived < fileSize) {
                    bytesRead = stream->Read(buffer, 0, buffer->Length);
                    if (bytesRead == 0) break;

                    fs->Write(buffer, 0, bytesRead);
                    totalReceived += bytesRead;

                    // TÍNH TOÁN %
                    int percent = (int)((totalReceived * 100) / fileSize);

                    // Cập nhật UI 
                    if (percent > lastPercent) {
                        lastPercent = percent;

                        // TÍNH TỐC ĐỘ (MB/s)
                        TimeSpan elapsed = DateTime::Now - startTime;
                        double seconds = elapsed.TotalSeconds;
                        String^ speedTxt = "Đang tải...";

                        if (seconds > 0) {
                            double speedMBps = (totalReceived / 1024.0 / 1024.0) / seconds;
                            speedTxt = Math::Round(speedMBps, 2).ToString() + " MB/s";
                        }

                        // Bắn dữ liệu về cho Form
                        if (onProgress != nullptr) {
                            onProgress(percent, speedTxt);
                        }
                    }
                }

                fs->Close();
                client->Close();
                return true;
            }
            catch (Exception^) {
                return false;
            }
        }
        static bool DownloadFromHttp(String^ url, String^ fileName, String^ saveFolder, Action<int, String^>^ onProgress)
        {
            try {
                System::Net::ServicePointManager::SecurityProtocol = (System::Net::SecurityProtocolType)3072;
                System::Net::HttpWebRequest^ request = (System::Net::HttpWebRequest^)System::Net::WebRequest::Create(url);
                request->Timeout = 5000;
                request->UserAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36";

                System::Net::HttpWebResponse^ response = (System::Net::HttpWebResponse^)request->GetResponse();
                long long fileSize = response->ContentLength;

                // CHỈ DÙNG ĐÚNG TÊN FILE MÀ GIAO DIỆN TRUYỀN XUỐNG
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
                        if (percent > lastPercent) {
                            lastPercent = percent;
                            TimeSpan elapsed = DateTime::Now - startTime;
                            double seconds = elapsed.TotalSeconds;
                            String^ speedTxt = "Đang tải...";
                            if (seconds > 0) {
                                double speedMBps = (totalReceived / 1024.0 / 1024.0) / seconds;
                                speedTxt = Math::Round(speedMBps, 2).ToString() + " MB/s";
                            }
                            if (onProgress != nullptr) onProgress(percent, speedTxt);
                        }
                    }
                }
                fs->Close();
                stream->Close();
                response->Close();
                return true;
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Lỗi Core: " + ex->Message);
                return false;
            }
        }
        // Backward-compatible overload without progress callback
        static bool DownloadFileFromTCPServer(String^ ip, int port, String^ fileName, String^ saveFolder)
        {
            return DownloadFileFromTCPServer(ip, port, fileName, saveFolder, nullptr);
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