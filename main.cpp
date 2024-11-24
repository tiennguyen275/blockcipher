#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Mã hóa: Hoán vị các ký tự trong bản rõ theo khóa hoán vị
string encrypt(const string &input, const vector<int> &key) {
    string result(input.size(), ' '); // Chuỗi kết quả có độ dài giống bản rõ
    for (size_t i = 0; i < key.size(); ++i) {
        result[i] = input[key[i]];
    }
    return result;
}

// Giải mã: Hoán vị ngược lại các ký tự trong bản mã theo khóa hoán vị
string decrypt(const string &input, const vector<int> &key) {
    string result(input.size(), ' '); // Chuỗi kết quả có độ dài giống bản mã
    for (size_t i = 0; i < key.size(); ++i) {
        result[key[i]] = input[i];
    }
    return result;
}

int main() {
    // Thiết lập console sử dụng mã hóa UTF-8
    system("chcp 65001");  // Set terminal to UTF-8 encoding

    // Nhập độ dài khối và khóa hoán vị
    int n;
    cout << "Nhập độ dài khối: ";
    cin >> n;

    vector<int> key(n);
    cout << "Nhập khóa hoán vị (" << n << " số, từ 0 đến " << n - 1 << "): ";
    for (int i = 0; i < n; ++i) {
        cin >> key[i];
    }

    // Nhập bản rõ
    string plaintext;
    cin.ignore(); // Loại bỏ ký tự xuống dòng
    cout << "Nhập bản rõ: ";
    getline(cin, plaintext);  // Đọc dòng vào với kiểu string

    // Đảm bảo độ dài bản rõ phù hợp với khóa hoán vị
    if (plaintext.size() < n) {
        cout << "Lưu ý: Độ dài bản rõ ngắn hơn khóa hoán vị. Đang thêm khoảng trắng." << endl;
        plaintext.append(n - plaintext.size(), ' '); // Thêm khoảng trắng nếu cần
    }

    // Mã hóa và giải mã
    string ciphertext = encrypt(plaintext, key);
    cout << "Bản mã: " << ciphertext << endl;

    string decryptedtext = decrypt(ciphertext, key);
    cout << "Bản giải mã: " << decryptedtext << endl;

    cout << "Ấn để thoát chương trình.";
    cin.get();
    
    return 0;
}
