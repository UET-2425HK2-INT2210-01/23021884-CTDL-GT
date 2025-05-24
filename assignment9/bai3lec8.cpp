#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;                 // Nh?p s? v?t v� t?ng tr?ng l�?ng t?i �a

    int w[100], v[100];           // m?ng tr?ng l�?ng v� gi� tr?
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];      // Nh?p t?ng c?p (tr?ng l�?ng, gi� tr?)
    }

    int dp[1001] = {0};           // dp[i] = gi� tr? t?i �a n?u tr?ng l�?ng l� i

    for (int i = 0; i < n; i++) {
        // Duy?t ng�?c �? tr�nh ghi �� tr?ng th�i tr�?c
        for (int j = X; j >= w[i]; j--) {
            if (dp[j - w[i]] + v[i] > dp[j]) {
                dp[j] = dp[j - w[i]] + v[i]; // c?p nh?t gi� tr? t?i �a
            }
        }
    }

    cout << dp[X] << endl;       // In ra gi� tr? l?n nh?t
    return 0;
}
