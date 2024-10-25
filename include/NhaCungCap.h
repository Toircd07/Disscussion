#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhaCungCap{
    private:
        string maNCC , tenNCC, tenSpNhap;
        double giaSanPham;
        string soLuong;
        string soDienThoai;
        vector<NhaCungCap> listNCC;

    public:
        NhaCungCap();
        NhaCungCap( string  maNCC , string tenNCC, string tenSpNhap, string soLuong, double giaSanPham, string soDienThoai);
        
        void themNCC();
        void xoaNCC();
        void suaNCC();
        void hienThidanhsachNCC();
        void timKiemNCC();
        void luuNCC();
        void docNCC();
        void hienThi(const int &i);

};

#endif // NHACUNGCAP_H