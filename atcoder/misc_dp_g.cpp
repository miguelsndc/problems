#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10;
int vis[ms], dp[ms];
vector<int> g[ms], order;
void dfs(int u) {
    vis[u] = true;
    for (int v: g[u]) if (!vis[v]) dfs(v);
    order.push_back(u);
}
void dale() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    reverse(order.begin(), order.end());
    for (auto u: order) {
        for (auto v: g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << *max_element(dp + 1, dp + n + 1) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}