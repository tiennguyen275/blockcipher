### Block Cipher - Hệ mật mã hoán vị cục bộ

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
   NNhập độ dài khối: 3<br>
   Nhập khóa hoán vị (3 số, từ 0 đến 2): 2 0 1<br>
   Nhập bản rõ: HELLO<br>

   Khối mã hóa 1: "HEL" hoán vị theo khóa [2, 0, 1] thành "LHE".<br>
   Khối mã hóa 2: "LO " hoán vị theo khóa [2, 0, 1] thành " LO".<br>
   Bản mã hoàn chỉnh: LHE LO<br>


## Mô tả thuật toán hoán vị cục bộ
   **Thuật toán mã hóa và giải mã sử dụng kỹ thuật hoán vị cục bộ, nơi mỗi khối của bản rõ (plaintext) được hoán vị theo một khóa xác định trước. Mỗi ký tự trong khối được thay thế bởi ký tự ở vị trí được xác định bởi khóa hoán vị. Quy trình hoạt động như sau:**

1. **Mã hóa:**

   > Dữ liệu bản rõ (plaintext) được chia thành các khối có độ dài cố định (block size).
   > Mỗi khối sẽ được mã hóa theo khóa hoán vị.
      # Ví dụ: Nếu khóa hoán vị là [2, 0, 1], khối "HEL" sẽ được mã hóa thành "LHE".
   > Chương trình sẽ tiếp tục mã hóa các khối tiếp theo tương tự.

2. **Giải mã:**

   > Dữ liệu mã hóa (ciphertext) sẽ được chia thành các khối và giải mã theo cùng một khóa hoán vị.
   > Mỗi khối mã hóa sẽ được giải mã theo khóa hoán vị ngược lại, phục hồi bản rõ.
   > Ví dụ: Khối mã hóa "LHE" khi giải mã sẽ trở lại "HEL".
      # Ví dụ về thuật toán:
      # Ví dụ mã hóa:

   2.1 **Khối đầu tiên: "HEL" và khóa hoán vị [2, 0, 1].**
      # Mỗi ký tự trong "HEL" sẽ được hoán vị theo khóa.
      # Kết quả là "LHE".
   2.2 **Khối thứ hai: "LO " và khóa hoán vị [2, 0, 1].**
      # Hoán vị ký tự theo khóa [2, 0, 1] sẽ cho ra " LO".
      # Kết quả mã hóa: "LHE LO".

   ***Giải mã:***
   2.3  **Khối mã hóa 1: "LHE" và khóa hoán vị [2, 0, 1].**
      # Hoán vị lại các ký tự trong "LHE" theo khóa sẽ phục hồi "HEL".

   2.4 **Khối mã hóa 2: " LO" và khóa hoán vị [2, 0, 1].**
      # Hoán vị lại các ký tự trong " LO" theo khóa sẽ phục hồi "LO ".
      # Kết quả giải mã: "HELLO".

   ***Các tính năng:***
      > + Mã hóa và giải mã dựa trên hoán vị cục bộ.
      > + Hỗ trợ tùy chỉnh độ dài khối và khóa hoán vị.
      > + Mã hóa và giải mã từng khối một cách chi tiết, hiển thị khóa hoán vị và kết quả cho từng khối.
   ***Lưu ý:***
      > + Đảm bảo rằng độ dài khối và khóa hoán vị phải hợp lệ (khóa hoán vị phải chứa đúng số phần tử tương ứng với độ dài khối).
      > + Các ký tự trong bản rõ sẽ được bổ sung thêm khoảng trắng nếu khối không đầy.