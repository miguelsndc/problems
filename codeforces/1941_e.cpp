#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, m, k, d; cin >> n >> m >> k >> d;
    vector grid(n, vector<int>(m));
    for (auto &v: grid) for (int &i: v) cin >> i;
    auto get = [&] (int r) -> ll {
        multiset<ll> ms;
        vector<ll> dp(m);
        ms.insert(1);
        dp[0] = 1;
        for (int i = 1; i < m; i++) {
            dp[i] = (ll)grid[r][i] + 1 + *ms.begin();   
            if (i - d - 1 >= 0) {
                ms.erase(ms.find(dp[i - d - 1]));
            }
            ms.insert(dp[i]);
        }
        return dp[m - 1];
    };
    ll ans = 1e15;
    vector<ll> ps(n + 1);
    for (int i = 0; i < n; i++) {
        ll cost = get(i);
        ps[i + 1] = ps[i] + cost;
    }
    for (int i = k; i <= n; i++) {
        ans = min(ans, ps[i] - ps[i - k]);
    } 
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}