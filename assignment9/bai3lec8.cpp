#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;                 // Nh?p s? v?t và t?ng tr?ng lý?ng t?i ða

    int w[100], v[100];           // m?ng tr?ng lý?ng và giá tr?
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];      // Nh?p t?ng c?p (tr?ng lý?ng, giá tr?)
    }

    int dp[1001] = {0};           // dp[i] = giá tr? t?i ða n?u tr?ng lý?ng là i

    for (int i = 0; i < n; i++) {
        // Duy?t ngý?c ð? tránh ghi ðè tr?ng thái trý?c
        for (int j = X; j >= w[i]; j--) {
            if (dp[j - w[i]] + v[i] > dp[j]) {
                dp[j] = dp[j - w[i]] + v[i]; // c?p nh?t giá tr? t?i ða
            }
        }
    }

    cout << dp[X] << endl;       // In ra giá tr? l?n nh?t
    return 0;
}
