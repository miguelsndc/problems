#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Kuhn {
    int n, m, iter = 0;
    vector<vector<int>> adj;
    vector<int> mt, vis;
    Kuhn(int n, int m) : n(n), m(m), adj(n), mt(m, -1), vis(n, 0) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
    bool dfs(int u) {
        vis[u] = iter;
        for (int v : adj[u]) {
            if (mt[v] == -1 or (vis[mt[v]] != iter and dfs(mt[v]))) {
                mt[v] = u;
                return true;
            }
        }
        return false;
    }
    int matching() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            iter++; if (dfs(i)) ans++;
        }
        return ans;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m, s, vel;
    while ((cin >> n >> m >> s >> vel)) {
        vector<double> gx(n), gy(n), hx(m), hy(m);
        for (int i = 0; i < n; i++) cin >> gx[i] >> gy[i];
        for (int i = 0; i < m; i++) cin >> hx[i] >> hy[i];
        Kuhn k(n, m);
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < m; v++) {
                double dx = gx[u] - hx[v];
                double dy = gy[u] - hy[v];
                double dist = sqrt(dx * dx + dy * dy);
                if ((dist / (vel + .0)) <= s) {
                    k.add_edge(u, v);
                }
            }
        }
        ll mt = k.matching();
        cout << n - mt << '\n';
    }
}