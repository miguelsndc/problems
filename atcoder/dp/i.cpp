#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<double> p(n);
    for (auto &i: p) cin >> i;
    vector dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int x = i - 1; x >= 0; x--) {
            // nao pego com prob 1 - p[i]
            dp[i][x] += dp[i - 1][x] * (1 - p[i - 1]);
            // pego
            dp[i][x + 1] += dp[i - 1][x] * p[i - 1];
        }
    }
    double ans = 0;
    for (int x = n; x > n / 2; x--) {
        ans += dp[n][x];
    }
    cout << setprecision(20) << fixed << ans << '\n';
}
