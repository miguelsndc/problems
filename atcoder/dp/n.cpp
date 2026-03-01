#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int mxn = 405;
int n; ll a[mxn], dp[mxn][mxn], ps[mxn];
template<typename T>
bool chmin(T&a, const T&b) {
    return (a > b ? a = b, true: false);
}
// ll f(int l, int r) {
//     if (l == r) return 0;
//     if (dp[l][r] != -1) return dp[l][r];
//     ll ans = 1e18;
//     for (int i = l; i + 1 <= r; i++) {  
//         ll left = f(l, i);
//         ll right = f(i + 1, r);
//         ll sum = ps[r + 1] - ps[l];
//         chmin(ans, left + right + sum);
//     }
//     return dp[l][r] = ans;
// }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = 1e18;
            ll sum = ps[r + 1] - ps[l];
            for (int k = l; k < r; k++) {
                chmin(dp[l][r], dp[l][k] + dp[k + 1][r] + sum);
            }
        }
    }
    cout << dp[0][n - 1];
}
