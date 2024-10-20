#include"KhachHang.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

KhachHang::KhachHang(){}
KhachHang::KhachHang(string maCus, string tenCus, string soCus, string email, int diemTichLuy)
    : maCus(maCus), tenCus(tenCus), soCus(soCus), email(email), diemTichLuy(diemTichLuy){};

void KhachHang::themCus(){
    cout << "Nhap ma khach hang: ";
       cin >> maCus;
       cin.ignore();
    cout << "Nhap ten khach hang: ";
        getline(cin, tenCus);
    cout << "Nhap so dien thoai: ";
        getline(cin, soCus);
    cout << "Nhap email: ";
        getline(cin, email);
    cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    cout << "Them khach hang thanh cong!" << endl;
    KhachHang* cus = new KhachHang(maCus, tenCus, soCus, email, diemTichLuy);
    danhSachCus.push_back(*cus);
}
void KhachHang::xoaCus(){
    cout << "Nhap ma khach hang can xoa: ";
       cin >> maCus;
    for (int i = 0; i < danhSachCus.size(); i++){
        if (danhSachCus[i].maCus == maCus){
            danhSachCus.erase(danhSachCus.begin() + i);
            cout << "Xoa khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
void KhachHang::suaCus(){
    cout << "Nhap ma khach hang can sua: ";
       cin >> maCus;
    cin.ignore();
    for (int i = 0; i < danhSachCus.size(); i++){
        if (danhSachCus[i].maCus == maCus){
              cout << "Nhap ten khach hang: ";
            getline(cin, danhSachCus[i].tenCus);
              cout << "Nhap so dien thoai: ";
            getline(cin, danhSachCus[i].soCus);
              cout << "Nhap email: ";
            getline(cin, danhSachCus[i].email);
              cout << "Nhap diem tich luy: ";
            cin >> danhSachCus[i].diemTichLuy;
              cout << "Sua khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
void KhachHang::timKiemCus(){
    string maCus;
    cout << "Nhap ma khach hang can tim: ";
    cin >> maCus;
    for (int i = 0; i < danhSachCus.size(); i++){
        if (danhSachCus[i].maCus == maCus){
             cout << "|  STT  |  Ma khach hang  |         Ten khach hang         |     So dien thoai     |             Email             |    Diem TL   |" << endl;
            hienThi(i);
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}
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
    cout << "|     " << danhSachCus[i].maCus ;
    for(int j=0; j<12-danhSachCus[i].maCus.length(); j++){
        cout << " ";
    }
    cout << "|  " << danhSachCus[i].tenCus ;
    for(int j=0; j<30-danhSachCus[i].tenCus.length(); j++){
        cout << " ";
    }
    cout << "|      " << danhSachCus[i].soCus ;
    for(int j=0; j<17-danhSachCus[i].soCus.length(); j++){
        cout << " ";
    }
    cout << "|    " << danhSachCus[i].email ;
    for(int j=0; j<27-danhSachCus[i].email.length(); j++){
        cout << " ";
    }
    cout << "|    " << danhSachCus[i].diemTichLuy ;
    for(int j=0; j<10-to_string(danhSachCus[i].diemTichLuy).length(); j++){
        cout << " ";
    }
    cout << "|" << endl;
}
    
void KhachHang::hienThiDSCus(){
    cout << "|  STT  |  Ma khach hang  |         Ten khach hang         |     So dien thoai     |             Email             |    Diem TL   |" << endl;
    for (int i = 0; i < danhSachCus.size(); i++){
        hienThi(i);
    }
}
void KhachHang::luuDSCus(){
    ofstream file("data/KhachHang.txt");
    for (int i = 0; i < danhSachCus.size(); i++){
        file << danhSachCus[i].maCus << ";";
        file << danhSachCus[i].tenCus << ";";
        file << danhSachCus[i].soCus << ";";
        file << danhSachCus[i].email << ";";
        file << danhSachCus[i].diemTichLuy << endl;
    }
    cout << "Luu danh sach khach hang thanh cong!" << endl;
    file.close();
}
void KhachHang::docDSCus(){
    ifstream file("data/KhachHang.txt");
    string diemTL;
    while (file.good()){
        getline(file, maCus,';');
        getline(file, tenCus,';');
        getline(file, soCus,';');
        getline(file, email,';');
        getline(file, diemTL,'\n');
     if(maCus != ""){
        int diemTichLuy = stoi(diemTL);
        KhachHang kh(maCus, tenCus, soCus, email, diemTichLuy);
        danhSachCus.push_back(kh);
       }
    }
    cout << "Doc danh sach khach hang thanh cong!" << endl;
    file.close();
}