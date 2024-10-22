#include"KhachHang.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

KhachHang::KhachHang(){}
KhachHang::KhachHang(string maCus, string tenCus, string sdtCus,string diaChi, string email, int diemTichLuy)
    : maCus(maCus), tenCus(tenCus), sdtCus(sdtCus),diaChi(diaChi), email(email), diemTichLuy(diemTichLuy){};

// Hàm thêm khách hàng
void KhachHang::themCus(){
    cout << "Nhap ma khach hang: ";
       cin >> maCus;
       cin.ignore();
    cout << "Nhap ten khach hang: ";
        getline(cin, tenCus);
    cout << "Nhap so dien thoai: ";
        getline(cin, sdtCus);
    cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    cout << "Nhap email: ";
        getline(cin, email);
    cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    cout << "Them khach hang thanh cong!" << endl;
    KhachHang* cus = new KhachHang(maCus, tenCus, sdtCus, diaChi, email, diemTichLuy);
    dsCus.push_back(*cus);
}
// Hàm xóa khách hàng
void KhachHang::xoaCus(){
    cout << "Nhap ma khach hang can xoa: ";
       cin >> maCus;
    for (int i = 0; i < dsCus.size(); i++){
        if (dsCus[i].maCus == maCus){
            dsCus.erase(dsCus.begin() + i);
            cout << "Xoa khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
// Hàm sửa khách hàng
void KhachHang::suaCus(){
    cout << "Nhap ma khach hang can sua: ";
       cin >> maCus;
    cin.ignore();
    for (int i = 0; i < dsCus.size(); i++){
        if (dsCus[i].maCus == maCus){
              cout << "Nhap ten khach hang: ";
            getline(cin, dsCus[i].tenCus);
              cout << "Nhap so dien thoai: ";
            getline(cin, dsCus[i].sdtCus);
              cout << "Nhap dia chi: ";
            getline(cin, dsCus[i].diaChi);
              cout << "Nhap email: ";
            getline(cin, dsCus[i].email);
              cout << "Nhap diem tich luy: ";
            cin >> dsCus[i].diemTichLuy;
              cout << "Sua khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
// Hàm tìm kiếm khách hàng
void KhachHang::timKiemCus(){
    string maCus;
    cout << "Nhap ma khach hang can tim: ";
    cin >> maCus;
    for (int i = 0; i < dsCus.size(); i++){
        if (dsCus[i].maCus == maCus){
                cout << "|  STT  |  Ma khach hang  |         Ten khach hang         |     So dien thoai     |           Dia chi          |             Email             |    Diem TL   |" << endl;            hienThi(i);
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
// Hàm hiển thị thông tin khách hàng
void KhachHang::hienThi(const int& i){
    cout << "|  " << i+1 ;
     int dem = 0 ;
        while(1){
            if(dem<5-to_string(i+1).length()){
                cout << " ";
                dem++;
            }else
                break ;
        }
    cout << "| " << dsCus[i].maCus ;
    for(int j=0; j<16-dsCus[i].maCus.length(); j++){
        cout << " ";
    }
    cout << "| " << dsCus[i].tenCus ;
    for(int j=0; j<31-dsCus[i].tenCus.length(); j++){
        cout << " ";
    }
    cout << "| " << dsCus[i].sdtCus ;
    for(int j=0; j<22-dsCus[i].sdtCus.length(); j++){
        cout << " ";
    }
    cout << "| " << dsCus[i].diaChi ;
    for(int j=0; j<26-dsCus[i].diaChi.length(); j++){
        cout << " ";
    }
    cout << "| " << dsCus[i].email ;
    for(int j=0; j<27-dsCus[i].email.length(); j++){
        cout << " ";
    }
    cout << "| " << dsCus[i].diemTichLuy ;
    for(int j=0; j<13-to_string(dsCus[i].diemTichLuy).length(); j++){
        cout << " ";
    }
    cout << "|" << endl;
}
// Hàm hiển thị danh sách khách hàng
void KhachHang::hienThiDSCus(){
    cout << "|  STT  |  Ma khach hang  |         Ten khach hang         |     So dien thoai     |           Dia chi          |             Email             |    Diem TL   |" << endl;
    for (int i = 0; i < dsCus.size(); i++){
        hienThi(i);
    }
}
// Hàm lưu danh sách khách hàng
void KhachHang::luuDSCus(){
    ofstream file("data/KhachHang.txt");
    for (int i = 0; i < dsCus.size(); i++){
        file << dsCus[i].maCus << ";";
        file << dsCus[i].tenCus << ";";
        file << dsCus[i].sdtCus << ";";
        file << dsCus[i].diaChi << ";";
        file << dsCus[i].email << ";";
        file << dsCus[i].diemTichLuy << endl;
    }
    cout << "Luu file thanh cong!" << endl;
    file.close();
}
// Hàm đọc danh sách khách hàng
void KhachHang::docDSCus(){
    ifstream file("data/KhachHang.txt");
    string diemTL;
    while (file.good()){
        getline(file, maCus,';');
        getline(file, tenCus,';');
        getline(file, sdtCus,';');
        getline(file, diaChi,';');
        getline(file, email,';');
        getline(file, diemTL,'\n');
     if(maCus != ""){
        int diemTichLuy = stoi(diemTL);
        KhachHang kh(maCus, tenCus, sdtCus, diaChi, email, diemTichLuy);
        dsCus.push_back(kh);
       }
    }
    cout << "Doc file thanh cong!" << endl;
    file.close();
}