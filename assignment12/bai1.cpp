#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1001;              // So luong cong viec toi da
vector<int> adj[MAXN];              // Danh sach ke: adj[u] chua cac cong viec phai lam sau khi lam xong u
bool visited[MAXN];                 // Mang danh dau dinh da duoc tham trong DFS
vector<int> result;                 // Mang luu ket qua thu tu cong viec theo sap xep topo
int n;                              // So luong cong viec

// Ham thuc hien DFS tu dinh u
void dfs(int u) {
    visited[u] = true;              // Danh dau u da duoc tham

    // Duyet cac dinh ke voi u (cac cong viec phai lam sau u)
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);                 // Goi de quy neu chua tham
        }
    }

    result.push_back(u);            // Them u vao ket qua (sau khi xu ly xong cac dinh ke)
}

int main() {
    int m;                          // So luong rang buoc (canh)
    cin >> n >> m;                  // Nhap so cong viec va so rang buoc

    // Khoi tao danh sach ke va visited
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }

    // Nhap m rang buoc: u phai lam truoc v
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);        // Them cung u ? v
    }

    // Chay DFS tu moi dinh chua tham
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Dao nguoc ket qua vi DFS them dinh sau khi tham xong
    reverse(result.begin(), result.end());

    // In ra thu tu cong viec hop le
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

