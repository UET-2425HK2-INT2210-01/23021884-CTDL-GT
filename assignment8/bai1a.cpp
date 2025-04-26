#include <iostream>
#include <algorithm>  // de dung std::swap
using namespace std;

// Ham phan hoach Lomuto
int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high];     // Chon pivot la phan tu cuoi cung
    int i = low - 1;           // i se chay va danh dau vung cac phan tu < pivot

    // Duyet j tu low den high-1
    for (int j = low; j < high; ++j) {
        // Neu arr[j] nho hon pivot, mo rong vung < pivot
        if (arr[j] < pivot) {
            ++i;               // tang chi so vung nho hon
            swap(arr[i], arr[j]);  // dua arr[j] vao vung < pivot
        }
    }

    // Dua pivot ve dung vi tri ngay sau vung < pivot
    swap(arr[i + 1], arr[high]);
    return i + 1;  // tra ve chi so cua pivot
}

// Ham sap xep nhanh Quick Sort
void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        // Phan hoach, lay vi tri pivot
        int pi = partitionLomuto(arr, low, high);
        // De quy sap trai cua pivot
        quickSortLomuto(arr, low, pi - 1);
        // De quy sap phai cua pivot
        quickSortLomuto(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Doc so luong phan tu
    cin >> n;

    // Cap phat mang dong de chua n so nguyen
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Doc tung phan tu
    }

    // Goi Quick Sort tren toan mang
    quickSortLomuto(arr, 0, n - 1);

    // In ra mang da sap xep
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';

    delete[] arr; 
    return 0;
}

