#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm mã hóa
string maHoa(const string& banRo, const vector<int>& khoa) {
    int doDaiKhoi = khoa.size();
    string ketQua = "";

    for (size_t i = 0; i < banRo.size(); i += doDaiKhoi) {
        string khoi = banRo.substr(i, doDaiKhoi);
        if (khoi.size() < doDaiKhoi) {
            khoi.append(doDaiKhoi - khoi.size(), 'X'); // Thêm padding
        }
        string khoiMaHoa(doDaiKhoi, ' ');
        for (int j = 0; j < doDaiKhoi; j++) {
            khoiMaHoa[j] = khoi[khoa[j]];
        }
        ketQua += khoiMaHoa;
    }
    return ketQua;
}

// Hàm giải mã
string giaiMa(const string& banMa, const vector<int>& khoa) {
    int doDaiKhoi = khoa.size();
    string ketQua = "";
    vector<int> khoaNguoc(doDaiKhoi);

    for (int i = 0; i < doDaiKhoi; i++) {
        khoaNguoc[khoa[i]] = i;
    }

    for (size_t i = 0; i < banMa.size(); i += doDaiKhoi) {
        string khoi = banMa.substr(i, doDaiKhoi);
        string khoiGiaiMa(doDaiKhoi, ' ');
        for (int j = 0; j < doDaiKhoi; j++) {
            khoiGiaiMa[j] = khoi[khoaNguoc[j]];
        }
        ketQua += khoiGiaiMa;
    }
    return ketQua;
}

// Hàm nhập khóa hoán vị
void nhapKhoa(vector<int>& khoa, int doDaiKhoi) {
    cout << "Nhap khoa hoan vi (" << doDaiKhoi << " so, tu 0 den " << doDaiKhoi - 1 << "): ";
    for (int i = 0; i < doDaiKhoi; i++) {
        cin >> khoa[i];
        if (khoa[i] < 0 || khoa[i] >= doDaiKhoi) {
            cout << "Khoa khong hop le!\n";
            exit(1);
        }
    }
}

// Hàm nhập chuỗi
string nhapChuoi(const string& thongBao) {
    cin.ignore(); // Xóa bộ đệm
    cout << thongBao;
    string chuoi;
    getline(cin, chuoi);
    return chuoi;
}

int main() {
    // Nhập độ dài khối
    int doDaiKhoi;
    cout << "Nhap do dai khoi: ";
    cin >> doDaiKhoi;

    // Nhập khóa hoán vị
    vector<int> khoa(doDaiKhoi);
    nhapKhoa(khoa, doDaiKhoi);

    // Nhập bản rõ
    string banRo = nhapChuoi("Nhap ban ro: ");

    // Mã hóa
    string banMa = maHoa(banRo, khoa);
    cout << "Ban ma: " << banMa << endl;

    // Giải mã
    string banGiaiMa = giaiMa(banMa, khoa);
    cout << "Ban giai ma: " << banGiaiMa << endl;

    cin.get();
    return 0;
}
