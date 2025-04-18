#include <iostream>
#include <string> 
using namespace std;

// Ham dung de quy de tao ra cac day 0,1 voi do dai la n 
void generateBinaryRecursive(string prefix, int n) {
    // Neu n = 0, in ra day nhi phan (prefix) hien tai
    if (n == 0) { 
        cout << prefix << endl; 
        return; 
    }
    // Goi de quy, them '0' vao dau hien tai va giam n
    generateBinaryRecursive(prefix + "0", n - 1); 
    // Goi de quy, them '1' vao dau hien tai va giam n
    generateBinaryRecursive(prefix + "1", n - 1);
}

int main() {
    int n;
    // Nhap vao do dai cua day nhi phan
    cin >> n;
    // Goi ham de quy de in ra cac day nhi phan co do dai n
    generateBinaryRecursive("", n);
    system("pause"); // Dung lai man hinh cho den khi nguoi dung nhan phim
}

