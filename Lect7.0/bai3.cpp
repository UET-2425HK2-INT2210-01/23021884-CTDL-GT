#include <iostream>
using namespace std;

// Ham de quy tinh so Fibonacci thu n
int fibonacci(int n) {
    if (n == 0)  // F(0) = 0
        return 0;
    else if (n == 1)  // F(1) = 1
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // F(n) = F(n-1) + F(n-2)
}

int main() {
    int n;  // Khai bao n
    cin >> n; 
    // In ket qua ra man hinh
    cout << fibonacci(n) << endl;

    return 0;
}

