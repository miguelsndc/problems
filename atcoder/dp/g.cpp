#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
    }
    vector<int> order, vis(n), dp(n, 0);
    auto dfs = [&] (auto &&self, int u) -> void {
        vis[u] = true;
        for (int v: g[u]) {
            if (!vis[v]) self(self, v);
        }
        order.push_back(u);
    };
    for (int u = 0; u < n; u++) if (!vis[u]) dfs(dfs, u);

    for (auto u: views::reverse(order)) {
        for (int v: g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
