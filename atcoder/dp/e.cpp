#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int inf = 1e9 + 10;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    int m = accumulate(v.begin(), v.end(), 0);
    vector<ll> dp(m + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int x = m; x >= 0; x--) {
            if (x - v[i] >= 0) dp[x] = min(dp[x], dp[x - v[i]] + w[i]);
        }
    }
    for (int x = m; x >= 0; x--) {
        if (dp[x] <= W) {
            cout << x << '\n';
            break;
        }
    }
}
