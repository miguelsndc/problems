#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10, mod = 1e9 + 7;
int n, m, vis[ms]; vector<int> g[ms], order;
ll ways[ms];
void dfs(int u) {
    vis[u] = true;
    for (int v: g[u]) if (!vis[v]) dfs(v);
    order.push_back(u);
}
void dale() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(1);
    reverse(order.begin(), order.end());
    ways[1] = 1;
    for (auto u: order) {
        if (!vis[u]) continue;
        for (int v: g[u]) {
            (ways[v] += ways[u]) %= mod;
        }
    }
    cout << ways[n] << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}