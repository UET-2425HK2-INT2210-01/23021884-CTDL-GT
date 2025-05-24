//S? d?ng �? quy & quay lui
#include <iostream>
using namespace std;

// H�m �? quy ki?m tra xem c� t?n t?i t?p con n�o c� t?ng b?ng X kh�ng
bool checkSubsetSum(int arr[], int n, int X, int index, int currentSum) {
    // N?u t?ng hi?n t?i b?ng X => �? t?m th?y t?p con h?p l?
    if (currentSum == X) return true;

    // N?u duy?t h?t m?ng ho?c t?ng v�?t qu� X => kh�ng h?p l?
    if (index == n || currentSum > X) return false;

    // G?i �? quy v?i tr�?ng h?p CH?N ph?n t? t?i v? tr� index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum + arr[index]))
        return true;

    // G?i �? quy v?i tr�?ng h?p KH�NG CH?N ph?n t? t?i v? tr� index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum))
        return true;

    // N?u c? hai nh�nh �?u kh�ng th?a m?n => tr? v? false
    return false;
}

int main() {
    int n, X;
    cin >> n >> X;  // Nh?p s? ph?n t? v� t?ng c?n t?m

    int arr[100];   // Khai b�o m?ng v?i k�ch th�?c t?i �a 100 ph?n t?
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Nh?p t?ng ph?n t?
    }

    // G?i h�m ki?m tra t? v? tr� �?u ti�n (index = 0), t?ng ban �?u = 0
    if (checkSubsetSum(arr, n, X, 0, 0))
        cout << "YES" << endl;  // N?u t?n t?i t?p con ph� h?p
    else
        cout << "NO" << endl;   // N?u kh�ng c� t?p con n�o th?a m?n

    return 0;
}
