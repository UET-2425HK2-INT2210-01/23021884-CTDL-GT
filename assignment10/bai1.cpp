#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;       // Danh sach ke de bieu dien do thi
vector<bool> visited;          // Mang danh dau cac dinh da duoc tham

// Ham DFS: Duyet toan bo cac dinh trong mot thanh phan lien thong bat dau tu dinh u
void dfs(int u) {
    visited[u] = true;         // Danh dau dinh u da duoc tham
    for (int v : adj[u]) {     // Duyet qua tat ca dinh ke voi u
        if (!visited[v]) {
            dfs(v);            // De quy DFS cho dinh ke chua duoc tham
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;             // Nhap so luong dinh (n) va canh (m)

    adj.resize(n + 1);         // Khoi tao danh sach ke (danh so tu 1 den n)
    visited.resize(n + 1, false); // Khoi tao mang visited voi gia tri false

    // Nhap m canh va xay dung danh sach ke
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;         // Nhap canh noi giua x va y
        adj[x].push_back(y);   // Them y vao danh sach ke cua x
        adj[y].push_back(x);   // Them x vao danh sach ke cua y (vi do thi vo huong)
    }

    int count = 0;             // Bien dem so luong thanh phan lien thong

    // Duyet qua tat ca cac dinh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {     // Neu dinh i chua duoc tham
            dfs(i);            // Thuc hien DFS tu dinh do
            count++;           // Tang so luong thanh phan lien thong len
        }
    }

    cout << count << endl;     // In ra so luong thanh phan lien thong

    return 0;
}

