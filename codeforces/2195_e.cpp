#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void dale() {
    int n; cin >> n;
    vector<int> lc(n + 1, 0), rc(n + 1, 0); 
    vector<ll> tempo(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> lc[i] >> rc[i];
    }
    auto dfs = [&](auto&& F, int u) -> void {
        if (lc[u] == 0) {
            tempo[u] = 1;
        } else {
            F(F, lc[u]);
            F(F, rc[u]);
            tempo[u] = 1 + (tempo[lc[u]] + 1 + tempo[rc[u]] + 1) % mod;
        }
    };
    auto resolve = [&](auto&& F, int u) -> void {
        if (lc[u] != 0) {
            dp[lc[u]] = (dp[u] + tempo[lc[u]]) % mod;
            F(F, lc[u]);
        }
        if (rc[u] != 0) {
            dp[rc[u]] = (dp[u] + tempo[rc[u]]) % mod;
            F(F, rc[u]);
        }
    };
    dfs(dfs, 1);
    dp[1] = tempo[1]; 
    resolve(resolve, 1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) dale();
}