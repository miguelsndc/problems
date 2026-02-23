#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define _sz(x) (int((x).size()))
const int maxn = 2e5 + 10;
int dp[maxn];
vector<pii> g[maxn];
void dfs1(int u, int p = -1) {
    for (auto [v, w]: g[u]) {
        if (v == p) continue;
        dp[1] += w;
        dfs1(v, u);
    }
}
/*
    u, v
    ja sei u
    u -> v devo inverter pra ser u <- v pra v chegar em u, dp[v] += 1
    senao seria u <- v ja sei u, em dp[u] eu inverto (u,v), em v eu nao inverto, ent tiro 1
    dp[v] = (w ? -1: 1)
*/
void dfs2(int u, int p = -1) {
    for (auto [v, w]: g[u]) {
        if (v == p) continue;
        dp[v] = dp[u] + (w ? -1: 1);
        dfs2(v, u);
    }
}
void arrocha() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    dfs1(1);
    dfs2(1);
    vi v; int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    for (int i = 1; i <= n; i++) if (dp[i] == ans) v.push_back(i);
    cout << ans << '\n';
    for (int i = 0; i < _sz(v); i++) {
        cout << v[i] << " \n"[i == _sz(v) - 1];
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) arrocha();
}