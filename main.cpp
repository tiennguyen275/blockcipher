#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm mã hóa theo hoán vị cục bộ
string localPermutationEncrypt(const string& plaintext, const vector<int>& key, int block_size) {
    string ciphertext = "";
    int n = plaintext.size();
    int block_count = 1;

    // Chia bản rõ thành các khối và mã hóa từng khối
    for (int i = 0; i < n; i += block_size) {
        string block = plaintext.substr(i, block_size);
        // Đảm bảo rằng khối có độ dài block_size
        if (block.size() < block_size) {
            block.append(block_size - block.size(), ' ');  // Thêm khoảng trắng nếu cần
        }

        // Mã hóa khối hiện tại
        string encrypted_block(block_size, ' ');
        for (int j = 0; j < block_size; ++j) {
            encrypted_block[j] = block[key[j]];  // Hoán vị các ký tự theo khóa
        }

        // In ra khóa hoán vị và khối mã hóa
        cout << "Khối thứ " << block_count << ": \"" << block << "\" -> khóa hoán vị: [";
        for (int k : key) {
            cout << k << " ";
        }
        cout << "] -> khối mã hóa: \"" << encrypted_block << "\"" << endl;

        ciphertext += encrypted_block;  // Thêm khối đã mã hóa vào bản mã
        block_count++;
    }

    return ciphertext;
}

// Hàm giải mã theo hoán vị cục bộ
string localPermutationDecrypt(const string& ciphertext, const vector<int>& key, int block_size) {
    string plaintext = "";
    int n = ciphertext.size();
    int block_count = 1;

    // Chia bản mã thành các khối và giải mã từng khối
    for (int i = 0; i < n; i += block_size) {
        string block = ciphertext.substr(i, block_size);

        // Giải mã khối hiện tại
        string decrypted_block(block_size, ' ');
        for (int j = 0; j < block_size; ++j) {
            decrypted_block[key[j]] = block[j];  // Hoán vị lại các ký tự để lấy bản rõ
        }

        // In ra khóa hoán vị và khối giải mã
        cout << "Khối mã hóa " << block_count << ": \"" << block << "\" -> khóa hoán vị: [ ";
        for (int k : key) {
            cout << k << " ";
        }
        cout << "] -> khối giải mã: \"" << decrypted_block << "\"" << endl;

        plaintext += decrypted_block;  // Thêm khối đã giải mã vào bản rõ
        block_count++;
    }

    return plaintext;
}

int main() {
    // Nhập độ dài khối và khóa hoán vị
    int block_size;
    cout << "Nhập độ dài khối: ";
    cin >> block_size;

    vector<int> key(block_size);
    cout << "Nhập khóa hoán vị (" << block_size << " số, từ 0 đến " << block_size - 1 << "): ";
    for (int i = 0; i < block_size; ++i) {
        cin >> key[i];
    }

    // Nhập bản rõ
    cin.ignore(); // Loại bỏ ký tự xuống dòng còn sót
    string plaintext;
    cout << "Nhập bản rõ: ";
    getline(cin, plaintext);

    // Mã hóa
    string ciphertext = localPermutationEncrypt(plaintext, key, block_size);
    cout << "Bản mã hoàn chỉnh: " << ciphertext << endl;

    // Giải mã
    string decryptedtext = localPermutationDecrypt(ciphertext, key, block_size);
    cout << "Bản giải mã hoàn chỉnh: " << decryptedtext << endl;

    cout << "Ấn phím bất kỳ để thoát chương trình";
    cin.get();
    
    return 0;
}
