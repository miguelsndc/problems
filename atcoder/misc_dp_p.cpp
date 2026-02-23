#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10, mod = 1e9 + 7;
vector<int> g[ms]; ll dp[ms][2];
void dfs(int u, int p = 0) {
    bool folha = true;
    ll p0 = 1, p1 = 1;
    for (int v: g[u]) {
        if (v == p) continue;
        folha = false;
        dfs(v, u);
        (p0 *= (dp[v][0] + dp[v][1]) % mod) %= mod;
        (p1 *= dp[v][0]) %= mod;
    }
    if (folha) dp[u][0] = dp[u][1] = 1;
    else dp[u][0] = p0, dp[u][1] = p1;
}
void dale() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % mod;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}