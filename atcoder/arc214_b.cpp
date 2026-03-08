#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void solve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<ii>());
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
    }
    if (n & 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> vis(n);
    int total = 0, other = 0;
    for (int i = 0; i <= n; i++) other ^= i;
    auto dfs = [&] (auto &&f, int u, int x) -> void {
        vis[u] = true;
        total ^= x;
        for (auto[v, w]: g[u]) {
            if (vis[v]) continue;
            f(f, v, x ^ w);
        }
    };
    dfs(dfs, 0, 0);
    cout << (total ^ other) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    int tt; cin >> tt;
    while(tt--) solve();
}
