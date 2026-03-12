#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 5005, inf = 1e9;
int dp[ms][ms];
char g[ms][ms];
int ps[ms][ms];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
        for (int j = 1; j <= n; j++) {
            ps[i][j] = ps[i][j - 1] + (g[i][j] == '#');
        }
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = inf;
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        int m = dp[i - 1][n];
        for (int j = n; j >= 0; j--) {
            m = min(m, dp[i - 1][j]);
            int branco = ps[i][j];
            int resto = (n - j) - (ps[i][n] - ps[i][j]);
            dp[i][j] = min(dp[i][j], m + branco + resto);
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}
