#include <iostream>
using namespace std;

// Ham tron hai mang con cua arr[]
void merge(int arr[], int left, int mid, int right) {
    // Kich thuoc cua hai mang con
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tao hai mang tam de chua du lieu hai nua
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy du lieu tu arr vao hai mang tam
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Chi so duyet mang tam va mang chinh
    int i = 0;      // chi so cho L[]
    int j = 0;      // chi so cho R[]
    int k = left;   // chi so cho arr[]

    // Tron hai mang con vao arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Neu con phan tu thua trong L[], copy het vao arr
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Neu con phan tu thua trong R[], copy het vao arr
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Giai phong bo nho mang tam
    delete[] L;
    delete[] R;
}

// Ham sap xep Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tinh chi so giua (tranh tran so)
        int mid = left + (right - left) / 2;

        // Sap xep nua trai
        mergeSort(arr, left, mid);

        // Sap xep nua phai
        mergeSort(arr, mid + 1, right);

        // Tron hai nua da sap
        merge(arr, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Doc so luong phan tu
    cin >> n;

    // Cap phat mang dong chua n phan tu
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Doc tung phan tu
    }

    // Goi Merge Sort tren toan mang
    mergeSort(arr, 0, n - 1);

    // In mang da sap xep (cach nhau mot dau cach)
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i + 1 < n ? ' ' : '\n');
    }

    delete[] arr;
    return 0;
}

