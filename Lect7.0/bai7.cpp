#include <iostream>
using namespace std;

// Ham de quy dao nguoc so nguyen duong n
void daoNguocSo(int n, int& revNum) {
    if (n == 0)
        return;
    
    revNum = revNum * 10 + (n % 10);  // Lay chu so cuoi cong vao revNum
    daoNguocSo(n / 10, revNum);       // Goi de quy voi phan con lai
}

int main() {
    int n;
    //Nhap so nguyen duong n
    cin >> n;
    int revNum = 0;
    daoNguocSo(n, revNum);

    cout << revNum << endl;

    return 0;
}

