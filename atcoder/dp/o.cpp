#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int mod = 1e9 + 7;
void add (ll &x, ll a) {
    x += a;
    if (x >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector g(n, vector<int>(n));
    for (auto &v: g) for (auto&i: v) cin >> i;
    vector<ll> dp((1 << n));
    dp[0] = 1;
    for (int m = 0; m < (1 << n); m++) {
        int k = __builtin_popcount(m);
        for (int j = 0; j < n; j++) {
            if (m & (1 << j)) continue;
            if (g[k][j]) {
                add(dp[m | (1 << j)], dp[m]);
            }
        }
    }
    cout << dp[(1<<n) -1];
}
