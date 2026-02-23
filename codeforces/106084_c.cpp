#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<tuple<int,int,int>> a(m);
        for (auto &[u, v, w]: a) {
            cin >> u >> v >> w;
        }
        vector<ll> dp(n + 1);
        for (int i = m - 1; i >= 0; i--) {
            auto [u, v, w] = a[i];
            ll vu = dp[u], vv = dp[v];
            dp[u] = vv + w;
            dp[v] = vu + w;
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}