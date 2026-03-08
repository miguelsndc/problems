#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int mod = 998244353;
struct DSU {
    vector<int> par, sz;
    int cnt = 0;
    DSU(int n) {
        cnt = n;
        par.assign(n, 0);
        sz.assign(n, 1);
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
        cnt--;
        return true; 
    }
};
const int mxn = 2e5 + 10;
ll pow2[mxn];
int main() {
    pow2[0] = 1;
    for (int i = 1; i < mxn; i++) {
        pow2[i] = (2ll * pow2[i - 1]) % mod;
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edges[i - 1] = {i, --u, --v}; 
    }
    sort(edges.rbegin(), edges.rend());
    DSU dsu(n);
    vector<array<int, 3>> mst;
    ll ans = 0;
    for (auto [w, u, v]: edges) {
        if (dsu.find(u) == dsu.find(v)) continue;
        if (dsu.cnt <= 2) {
            ans = (ans + pow2[w]) % mod;
        } else {
            dsu.unite(u, v);
        }
    }
    cout << ans;
}
