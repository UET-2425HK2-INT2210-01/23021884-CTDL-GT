#include <iostream>
using namespace std;

// Ham de quy dem so chu so cua mot so nguyen duong n
int demChuSo(int n) {
    if (n < 10)  // Neu n chi con 1 chu so thi tra ve 1
        return 1;
    return 1 + demChuSo(n / 10);  // Goi lai ham voi n bo chu so cuoi
}

int main() {
    int n;
    cin >> n;

    // In ket qua ra man hinh
    cout << demChuSo(n) << endl;

    return 0;
}

