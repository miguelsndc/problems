#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10;
vector<int> g[ms]; double dp[ms];
double dfs(int u, int p) {
    dp[u] = 0.0;
    int k = g[u].size() - (p != -1);
    for (int v: g[u]) {
        if (v == p) continue;
        dp[u] += (1.0 / k) * (dfs(v, u) + 1);
    }
    return dp[u];
}
void dale() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
   cout << setprecision(20) << fixed << dp[1] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}