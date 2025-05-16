#include <iostream>     // Thu vien nhap xuat chuan
#include <vector>       // Su dung vector cho danh sach ke
#include <queue>        // Su dung hang doi cho BFS

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;  // Nhap so dinh, so canh, dinh bat dau va dinh ket thuc

    // Khoi tao danh sach ke voi n+1 phan tu (vi dinh bat dau tu 1 den n)
    vector<vector<int>> adj(n + 1);

    // Mang danh dau dinh da duoc tham hay chua, khoi tao tat ca la false
    vector<bool> visited(n + 1, false);

    // Mang luu khoang cach ngan nhat tu dinh X den cac dinh khac, khoi tao la -1
    vector<int> distance(n + 1, -1);

    // Nhap m canh co huong
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Them canh co huong tu u den v
    }

    // Khoi tao BFS tu dinh X
    queue<int> q;
    q.push(X);              // Dua dinh X vao hang doi
    visited[X] = true;      // Danh dau da tham dinh X
    distance[X] = 0;        // Khoang cach tu X den X la 0

    // Bat dau thuat toan BFS
    while (!q.empty()) {
        int u = q.front();  // Lay dinh dau hang doi
        q.pop();            // Loai bo dinh dau khoi hang doi

        // Duyet cac dinh ke voi dinh u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;             // Danh dau da tham dinh v
                distance[v] = distance[u] + 1; // Cap nhat khoang cach tu X den v
                q.push(v);                     // Dua dinh v vao hang doi de duyet tiep
            }
        }
    }

    // In ra so canh cua duong di ngan nhat tu X den Y
    // Neu khong tim duoc duong di, distance[Y] se van la -1
    cout << distance[Y] << endl;

    return 0;
}

