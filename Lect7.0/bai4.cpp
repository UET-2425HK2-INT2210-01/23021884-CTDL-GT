#include <iostream>
using namespace std;

// Ham de quy tinh luy thua x^n
int luyThua(int x, int n) {
    if (n == 0)  // Dieu kien dung: x^0 = 1
        return 1;
    return x * luyThua(x, n - 1);  // x^n = x * x^(n-1)
}

int main() {
    int x, n;
    cin >> x >> n; 
    // In ket qua ra man hinh
    cout << luyThua(x, n) << endl;

    return 0;
}

