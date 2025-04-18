#include <bits/stdc++.h>       
using namespace std;

// Ham hoan vi 2 so nguyen
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham de quy sinh hoan vi
void generate(int a[], int l, int r) {
    if (l == r) {                    // Neu da co dinh het vi tri
        for (int i = 0; i <= r; i++) // In ra day hien tai
            cout << a[i];
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);              // Doi cho phan tu hien tai voi phan tu o vi tri l
            generate(a, l + 1, r);         // Goi de quy voi phan con lai
            swap(a[l], a[i]);              // Doi lai de quay lui
        }
    }
}

int main() {
    int n;
    cin >> n;              // Nhap vao so phan tu
    int a[10];             // Khai bao mang chua d?y hoán v?

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;  // Gán các giá tr? t? 1 ð?n n vào m?ng
    }
    generate(a, 0, n - 1); // Goi ham sinh hoan vi

    return 0;
}

