#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define ii pair<int, int>
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector dist(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> dist[i][j];
            dist[j][i] = dist[i][j];
        }
    }
    vector cand(n, vector<int>());
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j!= i and dist[0][j] + dist[i][j] == dist[0][i]) {
                cand[i].push_back(j);
            }
        }
    }
    vector tree(n, vector<ii>());
    for (int i = 1; i < n; i++) {
        if (!cand[i].size()) {
            // cout << "aqui 1\n";
            cout << "No\n";
            exit(0);
        }
        int ming = 1e9, g = -1;
        for (int c: cand[i]) {
            if (dist[i][c] < ming) {
                ming = dist[i][c];
                g = c;
            }
        }
        for (int c: cand[i]) {
            if (c == g) continue;
            if (ming == dist[i][c]) {
                // cout << "aqui 2\n";
                cout << "No\n";
                exit(0);
            }
        }
        tree[i].push_back({g, ming});
        tree[g].push_back({i, ming});
    }
    auto dfs = [&] (auto&& self, int u, int p, int d, vector<int> &dis) -> void{
        dis[u] = d;
        for (auto&[v, w]: tree[u]) {
            if (v == p) continue;
            self(self, v, u, d + w, dis);
        }
    };
    for (int u = 0; u < n; u++) {
        vector<int> d(n);
        dfs(dfs, u, -1, 0, d);
        for (int v = u + 1; v < n; v++) {
            if (d[v] != dist[u][v]) {
                // cout << "aqui 3\n";
                cout << "No\n";
                exit(0);
            }
        }
    }
    cout << "Yes\n";
}