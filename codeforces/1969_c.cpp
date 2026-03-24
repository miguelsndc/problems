#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> a(n);
    for (auto &x: a) cin >> x;
    const i64 inf = 1e18;
    vector dp(n + 1, vector<i64>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            i64 mn = inf;
            for (int d = 0; j + d <= k and i + d < n; d++) {
                mn = min(mn, a[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mn);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
