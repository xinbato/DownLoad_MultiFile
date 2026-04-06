#include "pch.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

// Hàm xử lý riêng cho từng Client (chạy ngầm)
void HandleClient(Object^ clientObj) {
    TcpClient^ client = (TcpClient^)clientObj;
    NetworkStream^ stream = client->GetStream();
    StreamReader^ reader = gcnew StreamReader(stream);
    BinaryWriter^ writer = gcnew BinaryWriter(stream);

    String^ serverDirectory = "D:\\Kho_File_Server\\";

    try {
        String^ request = reader->ReadLine();
        String^ serverDirectory = "D:\\Kho_File_Server\\";

        // 1. NẾU CLIENT MUỐN LẤY DANH SÁCH FILE
        if (request == "GET_LIST") {
            Console::WriteLine("[+] Client yeu cau lay danh sach file.");
            array<String^>^ files = Directory::GetFiles(serverDirectory);

            // Gửi số lượng file trước
            writer->Write((int)files->Length);

            // Gửi từng tên file
            for each (String ^ file in files) {
                writer->Write(Path::GetFileName(file));
            }
            Console::WriteLine("[OK] Da gui danh sach file.");
        }
        // 2. NẾU CLIENT MUỐN TẢI FILE (Logic cũ)
        else {
            String^ fileName = request; // Request lúc này chính là tên file
            Console::WriteLine("[+] Yeu cau tai file: " + fileName);
            String^ fullPath = serverDirectory + fileName;

            if (File::Exists(fullPath)) {
                FileInfo^ fileInfo = gcnew FileInfo(fullPath);
                writer->Write((long long)fileInfo->Length);

                FileStream^ fs = gcnew FileStream(fullPath, FileMode::Open, FileAccess::Read);
                array<Byte>^ buffer = gcnew array<Byte>(4096);
                int bytesRead;

                while ((bytesRead = fs->Read(buffer, 0, buffer->Length)) > 0) {
                    stream->Write(buffer, 0, bytesRead);
                }
                fs->Close();
                Console::WriteLine("[OK] Da gui xong: " + fileName);
            }
            else {
                writer->Write((long long)0);
                Console::WriteLine("[-] File khong ton tai!");
            }
        }
    }
    catch (Exception^) {}

    writer->Close();
    reader->Close();
    stream->Close();
    client->Close();
}

int main(array<System::String^>^ args)
{
    int port = 9000;
    TcpListener^ listener = gcnew TcpListener(IPAddress::Any, port);
    listener->Start();
    Console::WriteLine("Server Da Luong dang chay tai cong " + port + "...");

    while (true)
    {
        // Chấp nhận kết nối và lập tức quăng nó vào một Thread mới
        TcpClient^ client = listener->AcceptTcpClient();
        Thread^ clientThread = gcnew Thread(gcnew ParameterizedThreadStart(&HandleClient));
        clientThread->Start(client);
    }
    return 0;
}