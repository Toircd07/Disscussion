#ifndef QLKH_H
#define QLKH_H
#include<string>
#include<vector>

using namespace std ;
class KhachHang{
    private:
        string maCus;
        string tenCus;
        string sdtCus;
        string diaChi;
        string email;
        int diemTichLuy;
        vector<KhachHang> dsCus;
    public:
    KhachHang();
    KhachHang(string maCus, string tenCus, string sdtCus,string diaChi, string email, int diemTichLuy);
    void themCus();
    void xoaCus();
    void suaCus();
    void timKiemCus();
    void hienThi(const int& i);
    void hienThiDSCus();
    void luuDSCus();
    void docDSCus();
   
};   

#endif