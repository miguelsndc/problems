#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int mod = 1e9 + 7, mxn = 105, mxk = 1e5 + 10;
int a[mxn], n;
ll dp[mxn][mxk];
void add(ll& x, ll a) {
    x += a;
    if (x >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<ll> ps (k + 1);
        ps[0] = dp[i - 1][0];
        for (int j = 1; j <= k; j++) add(ps[j], ps[j - 1] + dp[i - 1][j]);
        // soma k ate k - a[i]
        for (int j = 0; j <= k; j++) {
            int L = j - a[i - 1];
            if (L <= 0) {
                add(dp[i][j], ps[j]);
            } else {
                add(dp[i][j], ps[j] - ps[L - 1] + mod);
            }
        }
    }
    cout << dp[n][k];
}
