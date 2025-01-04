#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void docDoThi(const string &tenFile, vector<int> &dinh, vector<vector<int>> &canh)
{
    ifstream file(tenFile);
    if (!file.is_open())
    {
        cerr << "Loi mo file." << endl;
        return;
    }

    string dong;
    getline(file, dong);
    stringstream ss(dong);
    int diem;
    while (ss >> diem)
    {
        dinh.push_back(diem);
    }

    while (getline(file, dong))
    {
        stringstream dongCanh(dong);
        int batDau, ketThuc, trongSo;
        dongCanh >> batDau >> ketThuc >> trongSo;
        canh.push_back({batDau, ketThuc, trongSo});
    }

    file.close();
}

vector<vector<int>> taoMaTranKe(int soDinh, const vector<vector<int>> &canh)
{
    vector<vector<int>> maTranKe(soDinh, vector<int>(soDinh, 0));

    for (const auto &canhDon : canh)
    {
        int batDau = canhDon[0] - 1;
        int ketThuc = canhDon[1] - 1;
        int trongSo = canhDon[2];

        maTranKe[batDau][ketThuc] = trongSo;
        maTranKe[ketThuc][batDau] = trongSo;
    }

    return maTranKe;
}

vector<vector<pair<int, int>>> taoDanhSachKe(int soDinh, const vector<vector<int>> &canh)
{
    vector<vector<pair<int, int>>> danhSachKe(soDinh);

    for (const auto &canhDon : canh)
    {
        int batDau = canhDon[0] - 1;
        int ketThuc = canhDon[1] - 1;
        int trongSo = canhDon[2];

        danhSachKe[batDau].push_back({ketThuc + 1, trongSo});
        danhSachKe[ketThuc].push_back({batDau + 1, trongSo}); // Giả sử đồ thị vô hướng
    }

    return danhSachKe;
}

void hienThiMaTranKe(const vector<vector<int>> &maTranKe)
{
    cout << "Ma tran ke:" << endl;
    for (const auto &dong : maTranKe)
    {
        for (int giaTri : dong)
        {
            cout << setw(3) << giaTri << " ";
        }
        cout << endl;
    }
}

// Hàm để hiển thị danh sách kề
void hienThiDanhSachKe(const vector<vector<pair<int, int>>> &danhSachKe)
{
    cout << "\nDanh sach ke:" << endl;
    for (int i = 0; i < danhSachKe.size(); ++i)
    {
        cout << i + 1 << ": ";
        for (const auto &ke : danhSachKe[i])
        {
            cout << "(" << ke.first << ", " << ke.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    string tenFile = "dothi4.txt";
    vector<int> dinh;
    vector<vector<int>> canh;

    docDoThi(tenFile, dinh, canh);

    int soDinh = dinh.size();

    vector<vector<int>> maTranKe = taoMaTranKe(soDinh, canh);
    vector<vector<pair<int, int>>> danhSachKe = taoDanhSachKe(soDinh, canh);

    hienThiMaTranKe(maTranKe);
    hienThiDanhSachKe(danhSachKe);

    return 0;
}
