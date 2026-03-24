#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector dp(n + 1, vector<i64>(5001, -1));
    auto dfs = [&] (auto&&self, int i, int sum) -> i64 {
        if (i == n) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        i64 res = max((a[i] + sum + 1) / 2, a[i]);
        return dp[i][sum] = (res + self(self, i + 1, a[i] + sum) + self(self, i + 1, sum)) % mod;
    };
    cout << dfs(dfs, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
