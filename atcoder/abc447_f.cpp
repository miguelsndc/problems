#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
void slve() {
    int n; cin >> n;
    vector tree(n, vector<int>());
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector<int> dp(n, 0);
    int ans = 1;
    auto dfs = [&] (auto &&self, int u, int p = -1) -> void {
        int mx1 = 0, mx2 = 0;
        for (int v: tree[u]) {
            if (v == p) continue;
            self(self, v, u);
            if (dp[v] > mx1) {
                mx2 = mx1;
                mx1 = dp[v];
            } else if (dp[v] > mx2) {
                mx2 = dp[v];
            }
        }

        if (deg[u] >= 4) {
            dp[u] = max(mx1 + 1, 1);
        } else {
            dp[u] = deg[u] == 3;
        }

        if (deg[u] >= 3) {
            ans = max(ans, mx1 + 1);
        }
        if (deg[u] >= 4 and mx1 > 0 and mx2 > 0) {
            ans = max(ans, mx1 + mx2 + 1);
        } 
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) slve();
}
