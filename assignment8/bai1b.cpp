#include <iostream>
#include <algorithm>  // de dung std::swap
using namespace std;

// Ham phan hoach theo so do Hoare
int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low];   // Chon pivot la phan tu dau vung low
    int i = low - 1;        // i se tang dan tu low-1 len
    int j = high + 1;       // j se giam dan tu high+1 xuong

    while (true) {
        // Tim arr[i] dau tien sao cho arr[i] >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Tim arr[j] dau tien sao cho arr[j] <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Neu hai con tro da gap hoac vuot nhau, phan hoach hoan thanh
        if (i >= j)
            return j;

        // Neu chua gap nhau, hoan vi de dua arr[i] ve phan "< pivot" va arr[j] ve phan "> pivot"
        swap(arr[i], arr[j]);
    }
}

// Ham sap xep nhanh su dung phan hoach Hoare
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        // Phan hoach va lay chi so pi
        int pi = partitionHoare(arr, low, high);
        // De quy sap vung trai (low..pi)
        quickSortHoare(arr, low, pi);
        // De quy sap vung phai (pi+1..high)
        quickSortHoare(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Doc so luong phan tu
    cin >> n;

    // Cap phat mang dong
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Doc tung phan tu
    }

    // Goi QuickSort voi phan hoach Hoare
    quickSortHoare(arr, 0, n - 1);

    // In mang da sap xep, cach nhau mot dau cach
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';

    delete[] arr;  
    return 0;
}

