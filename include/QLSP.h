#ifndef QLSP_H
#define QLSP_H

#include "SanPham.h"
#include <iostream>
#include <string>

using namespace std;

void QLSPmenu(){
    SanPham sp;
    int luaChon;
        sp.docSanPham();
    do{
        cout<<"1. Them san pham"<<endl;
        cout<<"2. Xoa san pham"<<endl;
        cout<<"3. Sua san pham"<<endl;
        cout<<"4. Hien thi danh sach san pham"<<endl;
        cout<<"5. Tim kiem san pham"<<endl;
        cout<<"6. Luu san pham"<<endl;
        cout<<"0. Thoat"<<endl;
        cin >> luaChon;
        switch(luaChon){
            case 1:
                sp.themSanPham();
                break;
            case 2:
                sp.xoaSanPham();
                break;
            case 3:
                sp.suaSanPham();
                break;
            case 4:
                sp.hienThiDanhSachSanPham();
                break;
            case 5:
                sp.timKiemSanPham();
                break;
            case 6:
                sp.luuSanPham();
                break;
            case 0:
                cout<<"Ket thuc chuong trinh"<<endl;
                break;
            default:
                cout<<"Lua chon khong hop le"<<endl;
                break;
        }
    }while(luaChon != 0);
}

#endif // QLSP_H