# Block Cipher - Hệ mật mã hoán vị cục bộ

Đây là một dự án mô phỏng hệ mật mã hoán vị cục bộ trong C++. Chương trình sẽ mã hóa và giải mã một chuỗi theo khóa hoán vị.

## Cấu trúc dự án

- `main.cpp`: Chứa mã nguồn chính, định nghĩa hàm mã hóa và giải mã, nhập và xuất dữ liệu.
- `README.md`: Tài liệu mô tả dự án, hướng dẫn sử dụng.

## Cách sử dụng

1. Biên dịch chương trình:
   g++ -o BlockCipher main.cpp
2. Chạy chương trình:
   ./BlockCipher

## Ví dụ chạy chương trình:
   Nhập độ dài khối: 4<br>
   Nhập khóa hoán vị (4 số, từ 0 đến 3): 1 3 2 0<br>
   Nhập bản rõ: HELLO<br>
   Bản mã: EHOLL<br><br>

   Nhập bản mã: EHOLL<br>
   Bản giải mã: HELLO
