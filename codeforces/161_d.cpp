#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 5e4 + 5, mxk = 5e2 + 5;
int dp[mxn][mxk], n, k; 
ll ans = 0;
vector<int> tree[mxn];
void dfs(int u, int p) {
    dp[u][0] = 1;
    for (int v: tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int j = 1; j <= k; j++) {
            ans += 1ll * dp[u][k - j] * dp[v][j - 1];
        }
        for (int j = 0; j < k; j++) {
            dp[u][j + 1] += dp[v][j];
        }
    }
}
void dale() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}