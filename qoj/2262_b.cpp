#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
ll dp[65][2][2][2];
ll solve_dp(ll X, int b, int smaller, int ant, int has_11) {
    if (b < 0) return has_11;
    ll &ans = dp[b][smaller][ant][has_11];
    if (~ans) return ans;
    ans = 0; 
    int on = (X & (1ll << b)) ? 1: 0;
    for (int i = 0; i <= (smaller ? 1: on); i++) {
        bool smaller_now = (smaller || i < on);
        ans += solve_dp(X, b - 1, smaller_now, i, has_11 | (i and ant));
    }
    return dp[b][smaller][ant][has_11];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        memset(dp, -1, sizeof dp);
        ll l, r; cin >> l >> r;
        ll R = solve_dp(r, 62, 0, 0, 0);
        memset(dp, -1, sizeof dp);
        ll L = 0;
        if (l - 1 >= 0) {
            L = solve_dp(l - 1, 62, 0, 0, 0);
        }
        cout << R - L << '\n';
    }
}