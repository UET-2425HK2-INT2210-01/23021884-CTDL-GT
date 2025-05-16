#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

// Su dung gia tri vo cuc de bieu thi "khong co duong di"
const int INF = INT_MAX;

int main() {
    // Mo file dau vao (chua thong tin ban do cac thanh pho va do ban cua duong di)
    ifstream fin("dirty.txt");

    // Mo file dau ra de ghi ket qua
    ofstream fout("dirty.out");

    int n, m, s, e; // n: so thanh pho, m: so duong, s: diem xuat phat, e: diem dich
    fin >> n >> m >> s >> e;

    // Tao ma tran khoang cach (dist), ban dau gan INF cho moi cap (i, j)
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Ma tran next luu dinh tiep theo tren duong di ngan nhat tu i den j
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    // Doc m canh tu file (moi canh co: u v d nghia la duong tu u den v co do ban d)
    for (int i = 0; i < m; i++) {
        int u, v, d;
        fin >> u >> v >> d;
        dist[u][v] = d;
        next[u][v] = v;
    }

    // Dat do ban tu 1 dinh den chinh no la 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    // ---------- Thuat toan Floyd-Warshall bat dau ----------
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
    // ---------- Ket thuc Floyd-Warshall ----------

    // --- Ghi ket qua duong di tu s den e ---
    if (dist[s][e] == INF) {
        fout << "INF" << endl;        // Khong co duong di
    } else {
        fout << dist[s][e] << endl;   // Do ban nho nhat tu s den e
    }

    // --- Truy vet va ghi duong di tu s den e ---
    if (next[s][e] == -1) {
        fout << "No path" << endl;    // Khong co duong
    } else {
        vector<int> path;
        int current = s;

        while (current != e) {
            path.push_back(current);
            current = next[current][e];
            if (current == -1) break;
        }

        path.push_back(e); // Them dinh dich

        for (int i = 0; i < path.size(); i++) {
            fout << path[i];
            if (i != path.size() - 1) fout << " ";
        }
        fout << endl;
    }

    // --- Ghi ma tran khoang cach ngan nhat giua moi cap dinh ---
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                fout << "INF";
            else
                fout << dist[i][j];

            if (j != n) fout << " ";
        }
        fout << endl;
    }

    return 0;
}

