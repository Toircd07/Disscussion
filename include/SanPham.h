#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
#include <vector>

using namespace std;

class SanPham{
    private:
        string maSanPham,tenSanPham,HSD;
        double giaBan;
        int soLuong;
        vector<SanPham> danhSachSanPham;

    public:
        SanPham();
        SanPham(string maSanPham, string tenSanPham, string HSD ,double giaBan, int soLuong);
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
