#include"NhaCungCap.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

NhaCungCap::NhaCungCap(){}
NhaCungCap::NhaCungCap(string maNCC ,string tenNCC, string tenSpNhap, string soLuong, double giaSanPham, string soDienThoai)
    :  maNCC(maNCC) ,tenNCC(tenNCC), tenSpNhap(tenSpNhap), soLuong(soLuong), giaSanPham(giaSanPham), soDienThoai(soDienThoai){};

void NhaCungCap::themNCC(){
    cout << "Nhap ma nha cung cap: ";
    cin >> maNCC;
    cin.ignore();
    cout << "Nhap ten nha cung cap: ";
    getline(cin, tenNCC);
    cout << "Nhap ten san pham nhap: ";
    getline(cin, tenSpNhap);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap gia san pham: ";
    cin >> giaSanPham;
    cout << "Nhap so dien thoai: ";
    cin >> soDienThoai;
            cout <<"                        "<<"================================= " << endl;
            cout <<"                        "<<"[ Them nha cung cap thanh cong! ] " << endl;
            cout <<"                        "<<"================================= " << endl;    
    NhaCungCap* ncc = new NhaCungCap(maNCC, tenNCC, tenSpNhap, soLuong, giaSanPham, soDienThoai);
    listNCC.push_back(*ncc);
}
void NhaCungCap::xoaNCC(){
    string maNCC;
    cout << "Nhap ma nha cung cap can xoa: ";
    cin >> maNCC;
    for (int i = 0; i < listNCC.size(); i++){
        if (listNCC[i].maNCC == maNCC){
            listNCC.erase(listNCC.begin() + i);
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"[ Xoa nha cung cap thanh cong! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
            return;
        }
    }
    cout <<"                        "<<"================================ " << endl;
    cout <<"                        "<<"[ Khong tim thay nha cung cap! ] " << endl;
    cout <<"                        "<<"================================ " << endl;
}

void NhaCungCap::suaNCC(){
    string maNCC;
    cout << "Nhap ma nha cung cap can sua: ";
    cin >> maNCC;
    cin.ignore();
    for (int i = 0; i < listNCC.size(); i++){
        if (listNCC[i].maNCC == maNCC){
            cout << "Nhap ten nha cung cap: ";
            getline(cin, listNCC[i].tenNCC);
            cout << "Nhap ten san pham nhap: ";
            getline(cin, listNCC[i].tenSpNhap);
            cout << "Nhap so luong: ";
            getline(cin, listNCC[i].soLuong);
            cout << "Nhap gia san pham: ";
            cin >> listNCC[i].giaSanPham;
            cout << "Nhap so dien thoai: ";
            getline(cin,  listNCC[i].soDienThoai);
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"[ Sua nha cung cap thanh cong! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
            return;
        }
    }
    cout <<"                        "<<"================================ " << endl;
    cout <<"                        "<<"[ Khong tim thay nha cung cap! ] " << endl;
    cout <<"                        "<<"================================ " << endl;
}
void NhaCungCap :: hienThi(const int &i){
    cout << "|  " << i+1 ;
        int dem = 0 ;
        while(1){
            if(dem<7-to_string(i+1).length()){
                cout << " ";
                dem++;
            }else
                break ;
        }
        cout << "|      " << listNCC[i].maNCC ;
        for(int  j=0; j<15-listNCC[i].maNCC.length(); j++){
            cout << " ";
        }
        cout << "|   " << listNCC[i].tenNCC ;
        for(int  j=0; j<33-listNCC[i].tenNCC.length(); j++){
            cout << " ";
        }
        cout << "|   " << listNCC[i].tenSpNhap ;
        for(int  j=0; j<27-listNCC[i].tenSpNhap.length(); j++){
            cout << " ";
        }
        cout << "|    " << listNCC[i].soLuong ;
        for(int  j=0; j<12-listNCC[i].soLuong.length(); j++){
            cout << " ";
        }
        cout << "|     " << listNCC[i].giaSanPham ;
        for(int  j=0; j<20-to_string(listNCC[i].giaSanPham).length(); j++){
            cout << " ";
        }
        cout << "|    " << listNCC[i].soDienThoai ;
        for(int  j=0; j<15-listNCC[i].soDienThoai.length(); j++){
            cout << " ";
        }
        cout << "|" << endl;

}
void NhaCungCap::hienThidanhsachNCC(){
    cout <<"                                                        "<< "========================== " << endl;
    cout <<"                                                        "<< "[ Danh sach nha cung cap ] " << endl;
    cout <<"                                                        "<< "========================== " << endl;
    cout <<"                                                        "<< "                           " << endl;
    cout <<"                                                        "<< "                           " << endl;

    cout << "|   STT   |   Ma nha cung cap   |          Ten nha cung cap          |      Ten san pham nhap       |    So luong    |   Gia san pham   |   So dien thoai   |" << endl;
    for (int i = 0; i < listNCC.size(); i++){
        hienThi(i);
    }
}
void NhaCungCap::timKiemNCC(){
    string maNCC;
    cout << "Nhap ma nha cung cap can tim: ";
    cin >> maNCC;
    for (int i = 0; i < listNCC.size(); i++){
        if (listNCC[i].maNCC == maNCC){
    cout << "|   STT   |   Ma nha cung cap   |          Ten nha cung cap          |      Ten san pham nhap       |    So luong    |   Gia san pham   |   So dien thoai   |" << endl;
            hienThi(i);
            return;
        }
    }
    cout <<"                            "<<"================================ " << endl;
    cout <<"                            "<<"[ Khong tim thay nha cung cap! ] " << endl;
    cout <<"                            "<<"================================ " << endl;
}

void NhaCungCap::luuNCC(){
    ofstream file("data/nhacungcap.txt");
    for (int i = 0; i < listNCC.size(); i++){
        file << listNCC[i].maNCC << ";" ;
        file << listNCC[i].tenNCC << ";" ;
        file << listNCC[i].tenSpNhap << ";" ;
        file << listNCC[i].soLuong << ";" ;
        file << listNCC[i].giaSanPham << ";" ;
        file << listNCC[i].soDienThoai << endl;
    }
    cout << "                       " <<"========================================== " << endl;
    cout << "                       " <<"[ Luu danh sach nha cung cap thanh cong! ] " << endl;
    cout << "                       " <<"========================================== " << endl;
    file.close();
}

void NhaCungCap::docNCC(){
    ifstream file("data/nhacungcap.txt");
    string  giaSanPhamStr;
    while (file.good()){
        getline(file, maNCC, ';');
        getline(file, tenNCC, ';');
        getline(file, tenSpNhap, ';');
        getline(file, soLuong, ';');
        getline(file, giaSanPhamStr, ';');
        getline(file, soDienThoai, '\n');

        if (maNCC != ""){
            double giaSanPham = stod(giaSanPhamStr);
           NhaCungCap ncc(maNCC, tenNCC, tenSpNhap, soLuong, giaSanPham, soDienThoai);
            listNCC.push_back(ncc);
        }
    }
    cout << "                       "<<"========================================== " << endl;
    cout << "                       "<<"[ Doc danh sach nha cung cap thanh cong! ] " << endl;
    cout << "                       "<<"========================================== " << endl;   
    file.close();
}