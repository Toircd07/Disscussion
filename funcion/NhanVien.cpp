#include"NhanVien.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

NhanVien::NhanVien(){};
NhanVien::NhanVien(string maNV, string hoTen, string caLamViec, string soDT, string email)
  : maNV(maNV), hoTen(hoTen), caLamViec(caLamViec), soDT(soDT), email(email){};
     
void NhanVien::ThemNhanVien(){
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ca lam viec: ";
    cin >> caLamViec;
    cout << "Nhap so dien thoai: ";
    cin >> soDT;
    cout << "Nhap email: ";
    cin >> email ;
    cout << "Them nhan vien thanh cong!" << endl;
    NhanVien* nv = new NhanVien(maNV, hoTen, caLamViec, soDT, email);
    listNV.push_back(*nv);
}
void NhanVien::XoaNhanVien(){
    string maNV;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> maNV;
    for(int i = 0; i < listNV.size(); i++){
        if(listNV[i].maNV == maNV){
            listNV.erase(listNV.begin() + i);
            cout << "Xoa thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}
void NhanVien::SuaNhanVien(){
    string maNV;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> maNV;
    for(int i = 0; i < listNV.size(); i++){
        if(listNV[i].maNV == maNV){
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, listNV[i].hoTen);
            cout << "Nhap ca lam viec moi: ";
            cin >> listNV[i].caLamViec;
            cout << "Nhap so dien thoai moi: ";
            cin >> listNV[i].soDT;
            cout << "Nhap email moi: ";
            cin >> listNV[i].email;
            cout << "Sua thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}
void NhanVien::TimKiemNhanVien(){
    string maNV;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNV;
    for(int i = 0; i < listNV.size(); i++){
        if(listNV[i].maNV == maNV){
            cout << "|  STT  |      ID      |        Ho va ten      |   Ca lam viec  |   So dien thoai   |               Email              |" << endl;
            HienThi(i);
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void NhanVien::HienThi(const int& i) {
    cout <<"| " << i+1 ;
    int dem =0 ;
    while(1){
        if(dem<6-to_string(i+1).length()){
            cout << " ";
            dem++;
        }
        else break;
    }
    cout << "| " << listNV[i].maNV;
    for(int j = 0; j < 13 - listNV[i].maNV.length(); j++){
        cout << " ";
    }
    cout << "|  " << listNV[i].hoTen;
    for(int j = 0; j < 21 - listNV[i].hoTen.length(); j++){
        cout << " ";
    }
    cout << "|     " << listNV[i].caLamViec;
    for(int j = 0; j < 11- listNV[i].caLamViec.length(); j++){
        cout << " ";
    }
    cout << "|     " << listNV[i].soDT;
    for(int j = 0; j < 14 - listNV[i].soDT.length(); j++){
        cout << " ";
    }
    cout << "| " << listNV[i].email;
    for(int j = 0; j < 33 - listNV[i].email.length(); j++){
        cout << " ";
    }
    cout << "|" << endl;
}
void NhanVien::HienThiDanhSachNhanVien(){

        cout << "|  STT  |      ID      |        Ho va ten      |   Ca lam viec  |   So dien thoai   |               Email              |" << endl;
    for(int i = 0; i < listNV.size(); i++){
        HienThi(i);
    }
}

void NhanVien::LuuDSNhanVien(){
    ofstream file("data/nhanvien.txt");
    for(int i = 0; i < listNV.size(); i++){
        file << listNV[i].maNV << ";" ;
        file << listNV[i].hoTen << ";" ;
        file << listNV[i].caLamViec << ";" ;
        file << listNV[i].soDT << ";" ;
        file << listNV[i].email << endl;
    }
    cout << "Luu file thanh cong!" << endl;
    file.close();
}

void NhanVien::DocDSNhanVien(){
    ifstream file("data/nhanvien.txt");
     if (!file.is_open()) {
        cout << "Khong the mo file de doc!" << endl;
        return;
    }
    listNV.clear();
    while(getline(file, maNV, ';')){
        getline(file, hoTen,';');
        getline(file, caLamViec,';');
        getline(file, soDT,';');
        getline(file, email,'\n');
        if(!maNV.empty()){
            NhanVien nv(maNV, hoTen, caLamViec, soDT, email);
        listNV.push_back(nv);
        }
    }
    cout << "Doc file thanh cong!" << endl;
    file.close();
}