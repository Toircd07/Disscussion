#include"KhachHang.h"
#include<string>
#include<iostream>

using namespace std;

void QLKHmenu() {
    KhachHang kh;
    int choice;
    kh.docDSCus();
    do {
        cout << "1. Them khach hang"  << " | " 
        << "2. Xoa khach hang" << " | " 
        << "3. Sua khach hang" << " | " 
        <<"4. Tim kiem khach hang" << " | " 
        <<"5. Hien thi danh sach khach hang" << " | " 
        <<"6. Luu danh sach khach hang" << " | " 
        << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            kh.themCus();
            break;
        case 2:
            kh.xoaCus();
            break;
        case 3:
            kh.suaCus();
            break;
        case 4:
            kh.timKiemCus();
            break;
        case 5:
            kh.hienThiDSCus();
            break;
        case 6:
            kh.luuDSCus();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice != 0);
}
