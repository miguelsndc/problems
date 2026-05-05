#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<int>(m));
    for (auto &v : g) for (auto &x: v) cin >> x;
    int t = gcd(g[0][0], g[n - 1][m - 1]);
    vector<int> div;
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            div.push_back(i);
            if (t / i != i) div.push_back(t / i);
        }
    }
    auto chega = [&](int x) {
        bitset<105> dp[n], d[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = (g[i][j] % x == 0);
            }
        }
        dp[0].set(0, d[0][0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!d[i][j]) continue;
                if (i - 1 >= 0) dp[i][j] = dp[i][j] | dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] = dp[i][j] | dp[i][j - 1];
            }
        };
        return dp[n-1][m-1];
    };
    int ans = 1;
    for (int x: div) {
        if (chega(x)) {
            ans = max(ans, x);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}