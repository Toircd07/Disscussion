#include "QLSP.h"
#include "QLNV.h"
#include "QLKH.h"
#include <iostream>

using namespace std;



int main(){
    int luaChon;
    do{
        cout << "--------------------------------" << endl;
        cout << "| Xin chao hay chon chuc nang! |"<<endl;
        cout << "--------------------------------" << endl;
        cout<<"1. Quan ly san pham"<<endl;
        cout<<"2. Quan ly nhan vien"<<endl;
        cout<<"3. Quan ly khach hang"<<endl;
        cout<<"0. Thoat"<<endl;
        cin >> luaChon;
        switch(luaChon){
            case 1:
                QLSPmenu();
                break;
            case 2:
                QLNhanVienmenu();
                break;
            case 3:
                QLKHmenu();
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