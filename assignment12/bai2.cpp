#include <iostream>
using namespace std;

// Cau truc bieu dien 1 canh (u, v, w): noi tu u den v voi trong so w
struct Edge {
    int u, v, w;
} edges[10001]; // Mang luu toi da 10,000 canh

int parent[1001]; // Mang cha dung cho Union-Find

// Tim dai dien cua tap chua dinh x (co nen duong di)
int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

// Gop hai tap chua x va y
void unite(int x, int y) {
    parent[find(x)] = find(y);
}

// Ham sap xep nhanh (QuickSort) cac canh theo trong so
void quickSort(int l, int r) {
    if (l >= r) return;
    int pivot = edges[(l + r) / 2].w;
    int i = l, j = r;
    while (i <= j) {
        while (edges[i].w < pivot) i++;
        while (edges[j].w > pivot) j--;
        if (i <= j) {
            swap(edges[i], edges[j]);
            i++; j--;
        }
    }
    quickSort(l, j);
    quickSort(i, r);
}

int main() {
    // Doc du lieu tu file
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    
    int n, m; // n: so dinh, m: so canh
    cin >> n >> m;

    // Nhap m canh (u, v, w)
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Khoi tao Union-Find: moi dinh la cha cua chinh no
    for (int i = 1; i <= n; i++) 
        parent[i] = i;

    // Sap xep tat ca cac canh theo trong so tang dan
    quickSort(0, m - 1);

    int total = 0;                 // Tong trong so cua cay khung
    int selected[10001], cnt = 0; // Mang luu chi so cac canh duoc chon vao MST

    // Duyet tung canh theo thu tu trong so tang
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;

        // Neu u va v thuoc hai tap khac nhau ? chon canh nay
        if (find(u) != find(v)) {
            unite(u, v);           // Gop hai tap lai
            total += w;            // Cong trong so vao tong
            selected[cnt++] = i;   // Ghi nhan canh duoc chon
        }
    }

    // In ra tong trong so cua cay khung
    cout << total << endl;

    // In ra danh sach cac canh thuoc cay khung nho nhat
    for (int i = 0; i < cnt; i++) {
        int idx = selected[i];
        cout << edges[idx].u << " " << edges[idx].v << " " << edges[idx].w << endl;
    }

    return 0;
}

