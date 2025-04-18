#include <iostream>
using namespace std;

// Ham de quy tinh tong cac so nguyen tu 1 den n
int tinhTong(int n) {
    if (n == 1)  // Dieu kien dung: neu n = 1 thi tra ve 1
        return 1;
    return n + tinhTong(n - 1);  // Goi lai ham voi n - 1 va cong voi n hien tai
}

int main() {
    int n ; 
    // nhap n 
	cin >> n; 
    // In ket qua ra man hinh
    cout << "Tong tu 1 den " << n << " la: " << tinhTong(n) << endl;

    return 0;  // Ket thuc chuong trinh
}

