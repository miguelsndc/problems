#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 35;
ll dp[mxn][mxn];
ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = C(n - 1, k - 1) + C(n - 1, k);
}
void dale() {
    int n, k; cin >> n >> k;
    int m = 31 - __builtin_clz(n);
    ll ans = 0;
    for (int bit = 0; bit < m; bit++) {
        for (int cnt =  1; cnt <= bit + 1; cnt++) {
            if ((cnt + bit) > k) {
                ans += C(bit, cnt - 1);
            }
        }
    }
    if (m + 1 > k) ans++;
    cout << ans << "\n";
}
int main() {
    for (int i = 0; i < mxn; i++)
        for (int j = 0; j < mxn; j++) dp[i][j] = -1;
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}