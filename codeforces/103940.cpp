#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

const int ms = 1e5 + 10;
vector<pii> g[ms]; 
vector<int> order;
const int mod = 1e9 + 7;
int vis[ms], dp[ms];

void topo(int u) {
    vis[u] = true;
    for (auto &[v, w]: g[u]) if (!vis[v]) topo(v);
    order.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c; cin >> n >> m >> c;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    topo(1);
    reverse(order.begin(), order.end());
    dp[1] = 1;
    for (int u: order) {
        if (!dp[u]) continue;
        for (auto &[v, w]: g[u]) {
            dp[v] = min(c + 1, dp[v] + dp[u] + w);
        }
    }
    vector<ll> coin(c + 1, 0);
    coin[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > c) continue;
        for (int v = dp[i]; v <= c; v++) {
            coin[v] = (coin[v] + coin[v - dp[i]]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= c; i++) ans = (ans + coin[i]) % mod;
    cout << ans << '\n';
}