#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<int> nxt(n, -1); map<int,int> last;
    vector<vector<int>> g(n);
    for (int i = n - 1; i >= 0; i--) {
        if (last.count(a[i] + 1)) {
            nxt[i] = last[a[i] + 1];
            if (nxt[i] != -1) {
                g[i].push_back(nxt[i]);
            }
        }
        last[a[i]] = i;
    }
    vector<int> order, vis(n);
    auto dfs = [&] (auto &&self, int u) -> void {
        vis[u] = true;
        for (int v: g[u]) {
            if (!vis[v]) self(self, v);
        }
        order.push_back(u);
    };
    for (int i = 0; i < n; i++) dfs(dfs, i);
    vector<int> dp(n, 1);
    reverse(order.begin(), order.end());
    for (auto u: order) {
        for (auto v: g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}