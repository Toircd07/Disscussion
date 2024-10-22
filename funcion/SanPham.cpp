
#include "SanPham.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SanPham::SanPham(){}
SanPham::SanPham(string maSP, string tenSP,string HSD, double giaBan, int soLuong)
    : maSP(maSP), tenSP(tenSP), HSD(HSD) ,giaBan(giaBan), soLuong(soLuong){};
void SanPham::themSanPham(){
    cout << "Nhap ma san pham: ";
    cin >> maSP;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    getline(cin, tenSP);
    cout << "Nhap HSD: ";
    getline(cin, HSD);
    cout << "Nhap gia ban: ";
    cin >> giaBan;
    cout << "Nhap so luong: ";
    cin >> soLuong;  
    cout << "Them san pham thanh cong!" << endl;
    SanPham* sp = new SanPham(maSP, tenSP, HSD, giaBan, soLuong);
    listsp.push_back(*sp);
}

void SanPham::xoaSanPham(){
    string maSP;
    cout << "Nhap ma san pham can xoa: ";
    cin >> maSP;
    for (int i = 0; i < listsp.size(); i++){
        if (listsp[i].maSP == maSP){
            listsp.erase(listsp.begin() + i);
            cout << "Xoa san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void SanPham::suaSanPham(){
    string maSP;
    cout << "Nhap ma san pham can sua: ";
    cin >> maSP;
    cin.ignore();
    for (int i = 0; i < listsp.size(); i++){
        if (listsp[i].maSP == maSP){
            cout << "Nhap ten san pham: ";
            getline(cin, listsp[i].tenSP);
            cout << "Nhap HSD: ";
            getline(cin, listsp[i].HSD);
            cout << "Nhap gia ban: ";
            cin >> listsp[i].giaBan;
            cout << "Nhap so luong: ";
            cin >> listsp[i].soLuong;
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
        cout << "|      " << listsp[i].maSP ;
        for(int  j=0; j<11-listsp[i].maSP.length(); j++){
            cout << " ";
        }
        cout << "|   " << listsp[i].tenSP ;
        for(int  j=0; j<33-listsp[i].tenSP.length(); j++){
            cout << " ";
        }
        cout << "|   " << listsp[i].HSD ;
        for(int  j=0; j<12-listsp[i].HSD.length(); j++){
            cout << " ";
        }
        cout << "|      "  << listsp[i].giaBan ;
        for(int  j=0; j<19-to_string(listsp[i].giaBan).length(); j++){
            cout << " ";
        }
        cout << "|    "  << listsp[i].soLuong ;
        for(int  j=0; j<10-to_string(listsp[i].soLuong).length(); j++){
            cout << " ";
        }
        cout << "|" << endl;
    }
void SanPham::hienThiDanhSachSanPham(){
     cout << "|   STT   |   Ma san pham   |            Ten san pham            |      HSD      |    Gia ban(K)    |   So luong   |" << endl;
    for (int i = 0; i < listsp.size(); i++){
        hienThi(i);
    }
}

void SanPham::timKiemSanPham(){
    string maSP;
    cout << "Nhap ma san pham can tim: ";
    cin >> maSP;
    for (int i = 0; i < listsp.size(); i++){

        if (listsp[i].maSP == maSP){
                cout << "|   STT   |   Ma san pham   |            Ten san pham            |      HSD      |    Gia ban(K)    |   So luong   |" << endl;
            hienThi(i);
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}
void SanPham::luuSanPham(){
    ofstream file("data/sanpham.txt");
    for (int i = 0; i < listsp.size(); i++){
        file << listsp[i].maSP << ";" ;
        file << listsp[i].tenSP << ";" ;
        file << listsp[i].HSD << ";" ;
        file << listsp[i].giaBan << ";" ;
        file << listsp[i].soLuong  << endl;
    }
    cout << "Luu san pham thanh cong!" << endl;
    file.close();
}
void SanPham :: docSanPham(){
    ifstream file("data/sanpham.txt");
    string giaBanStr, soLuongStr;
    while (file.good()){
        getline(file, maSP, ';');
        getline(file, tenSP, ';');
        getline(file, HSD, ';');
        getline(file, giaBanStr, ';');
        getline(file, soLuongStr, '\n');
         if (maSP != ""){
            double giaBan = stod(giaBanStr);
            int soLuong = stoi(soLuongStr);
            SanPham sp(maSP, tenSP,HSD, giaBan, soLuong);
            listsp.push_back(sp);
        }
    }
    cout << "Doc san pham thanh cong!" << endl;
    file.close();
}