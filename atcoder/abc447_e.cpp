#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int ms = 2e5 + 10, mod = 998244353;
long long pw[ms];
struct DSU {
    vector<int> par, sz;
    int cc;
    DSU(int n) {
        par.assign(n, 0);
        sz.assign(n, 1);
        cc = n;
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
        sz[x_root] += sz[y_root];
        par[y_root] = x_root;
        cc--;
        return true; 
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < ms; i++) {
        pw[i] = (2ll * pw[i - 1]) % mod;
    }

    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    long long total = 0;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2];
        edges[i][1]--; edges[i][2]--;
        edges[i][0] = i + 1;
        total = (total + pw[edges[i][0]]) % mod;
    }
    sort(edges.rbegin(), edges.rend());
    DSU dsu(n);
    long long cost = 0;
    for (auto &[i, u, v] : edges) {
        if (dsu.cc > 2) {
            dsu.unite(u, v);
            cost = (cost + pw[i]) % mod;
            continue;
        }

        if (dsu.find(u) == dsu.find(v)) {
            dsu.unite(u, v);
            cost = (cost + pw[i]) % mod;
        }
    }

    cout << (total - cost + mod) % mod;
}