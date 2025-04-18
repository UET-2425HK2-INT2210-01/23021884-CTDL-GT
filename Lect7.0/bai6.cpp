#include <iostream>
using namespace std;

// Ham de quy tinh tong cac chu so cua n
int tongChuSo(int n) {
    if (n < 10)  // Neu n chi con 1 chu so thi tra ve chinh no
        return n;
    return (n % 10) + tongChuSo(n / 10);  // Lay chu so cuoi + tong chu so cua phan con lai
}

int main() {
    int n;
    cin >> n;

    // In ket qua ra man hinh
    cout << tongChuSo(n) << endl;

    return 0;
}

