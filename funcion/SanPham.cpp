
#include "SanPham.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SanPham::SanPham(){}
SanPham::SanPham(string maSanPham, string tenSanPham,string HSD, double giaBan, int soLuong)
    : maSanPham(maSanPham), tenSanPham(tenSanPham), HSD(HSD) ,giaBan(giaBan), soLuong(soLuong){};
void SanPham::themSanPham(){
    cout << "Nhap ma san pham: ";
    cin >> maSanPham;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    getline(cin, tenSanPham);
    cout << "Nhap HSD: ";
    getline(cin, HSD);
    cout << "Nhap gia ban: ";
    cin >> giaBan;
    cout << "Nhap so luong: ";
    cin >> soLuong;  
    cout << "Them san pham thanh cong!" << endl;
    SanPham* sp = new SanPham(maSanPham, tenSanPham, HSD, giaBan, soLuong);
    danhSachSanPham.push_back(*sp);
}

void SanPham::xoaSanPham(){
    string maSanPham;
    cout << "Nhap ma san pham can xoa: ";
    cin >> maSanPham;
    for (int i = 0; i < danhSachSanPham.size(); i++){
        if (danhSachSanPham[i].maSanPham == maSanPham){
            danhSachSanPham.erase(danhSachSanPham.begin() + i);
            cout << "Xoa san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void SanPham::suaSanPham(){
    string maSanPham;
    cout << "Nhap ma san pham can sua: ";
    cin >> maSanPham;
    cin.ignore();
    for (int i = 0; i < danhSachSanPham.size(); i++){
        if (danhSachSanPham[i].maSanPham == maSanPham){
            cout << "Nhap ten san pham: ";
            getline(cin, danhSachSanPham[i].tenSanPham);
            cout << "Nhap HSD: ";
            getline(cin, danhSachSanPham[i].HSD);
            cout << "Nhap gia ban: ";
            cin >> danhSachSanPham[i].giaBan;
            cout << "Nhap so luong: ";
            cin >> danhSachSanPham[i].soLuong;
            cout << "Sua san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void SanPham::hienThi(const int& i){
    
        cout << "|  " << i+1 ;
        int dem = 0 ;
        while(1){
            if(dem<7-to_string(i+1).length()){
                cout << " ";
                dem++;
            }else{
                break ;}
        }
        cout << "|      " << danhSachSanPham[i].maSanPham ;
        for(int  j=0; j<11-danhSachSanPham[i].maSanPham.length(); j++){
            cout << " ";
        }
        cout << "|   " << danhSachSanPham[i].tenSanPham ;
        for(int  j=0; j<33-danhSachSanPham[i].tenSanPham.length(); j++){
            cout << " ";
        }
        cout << "|   " << danhSachSanPham[i].HSD ;
        for(int  j=0; j<12-danhSachSanPham[i].HSD.length(); j++){
            cout << " ";
        }
        cout << "|      "  << danhSachSanPham[i].giaBan ;
        for(int  j=0; j<19-to_string(danhSachSanPham[i].giaBan).length(); j++){
            cout << " ";
        }
        cout << "|    "  << danhSachSanPham[i].soLuong ;
        for(int  j=0; j<10-to_string(danhSachSanPham[i].soLuong).length(); j++){
            cout << " ";
        }
        cout << "|" << endl;


    }
void SanPham::hienThiDanhSachSanPham(){
     cout << "|   STT   |   Ma san pham   |            Ten san pham            |      HSD      |    Gia ban(K)    |   So luong   |" << endl;
    for (int i = 0; i < danhSachSanPham.size(); i++){
        hienThi(i);
    }
}

void SanPham::timKiemSanPham(){
    string maSanPham;
    cout << "Nhap ma san pham can tim: ";
    cin >> maSanPham;
    for (int i = 0; i < danhSachSanPham.size(); i++){

        if (danhSachSanPham[i].maSanPham == maSanPham){
        cout << "|  STT  |   Ma san pham   |            Ten san pham            |      HSD      |    Gia ban(k)    |   So luong   |" << endl;
            hienThi(i);
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}
void SanPham::luuSanPham(){
    ofstream file("data/sanpham.txt");
    for (int i = 0; i < danhSachSanPham.size(); i++){
        file << danhSachSanPham[i].maSanPham << ";" ;
        file << danhSachSanPham[i].tenSanPham << ";" ;
        file << danhSachSanPham[i].HSD << ";" ;
        file << danhSachSanPham[i].giaBan << ";" ;
        file << danhSachSanPham[i].soLuong  << endl;
    }
    cout << "Luu san pham thanh cong!" << endl;
    file.close();
}
void SanPham :: docSanPham(){
    ifstream file("data/sanpham.txt");
    string giaBanStr, soLuongStr;
    while (file.good()){
        getline(file, maSanPham, ';');
        getline(file, tenSanPham, ';');
        getline(file, HSD, ';');
        getline(file, giaBanStr, ';');
        getline(file, soLuongStr, '\n');
         if (maSanPham != ""){
            double giaBan = stod(giaBanStr);
            int soLuong = stoi(soLuongStr);
            SanPham sp(maSanPham, tenSanPham,HSD, giaBan, soLuong);
            danhSachSanPham.push_back(sp);
        }
    }
    cout << "Doc san pham thanh cong!" << endl;
    file.close();
}