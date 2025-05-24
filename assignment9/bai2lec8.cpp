//S? d?ng ð? quy & quay lui
#include <iostream>
using namespace std;

// Hàm ð? quy ki?m tra xem có t?n t?i t?p con nào có t?ng b?ng X không
bool checkSubsetSum(int arr[], int n, int X, int index, int currentSum) {
    // N?u t?ng hi?n t?i b?ng X => ð? t?m th?y t?p con h?p l?
    if (currentSum == X) return true;

    // N?u duy?t h?t m?ng ho?c t?ng vý?t quá X => không h?p l?
    if (index == n || currentSum > X) return false;

    // G?i ð? quy v?i trý?ng h?p CH?N ph?n t? t?i v? trí index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum + arr[index]))
        return true;

    // G?i ð? quy v?i trý?ng h?p KHÔNG CH?N ph?n t? t?i v? trí index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum))
        return true;

    // N?u c? hai nhánh ð?u không th?a m?n => tr? v? false
    return false;
}

int main() {
    int n, X;
    cin >> n >> X;  // Nh?p s? ph?n t? và t?ng c?n t?m

    int arr[100];   // Khai báo m?ng v?i kích thý?c t?i ða 100 ph?n t?
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Nh?p t?ng ph?n t?
    }

    // G?i hàm ki?m tra t? v? trí ð?u tiên (index = 0), t?ng ban ð?u = 0
    if (checkSubsetSum(arr, n, X, 0, 0))
        cout << "YES" << endl;  // N?u t?n t?i t?p con phù h?p
    else
        cout << "NO" << endl;   // N?u không có t?p con nào th?a m?n

    return 0;
}
