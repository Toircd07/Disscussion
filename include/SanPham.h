#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
#include <vector>

using namespace std;

class SanPham{
    private:
        string maSP,tenSP,HSD;
        double giaBan;
        int soLuong;
        vector<SanPham> listsp;

    public:
        SanPham();
        SanPham(string maSP, string tenSP, string HSD ,double giaBan, int soLuong);
        void themSanPham();
        void xoaSanPham();
        void suaSanPham();
        void hienThiDanhSachSanPham();
        void timKiemSanPham();
        void luuSanPham();
        void docSanPham();
        void hienThi(const int& i);

};

#endif // SANPHAM_H
