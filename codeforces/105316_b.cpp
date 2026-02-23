#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<vector<ll>>> dp(34, vector<vector<ll>>(10, vector<ll>(10)));
vector<ll> apply(vector<ll>& f) {
    vector<ll> g(10);
    for (int d = 1; d < 10; d++) {
        int v = d * 3;
        if (v < 10)
            g[v] += f[d];
        else {
            g[v / 10] += f[d];
            g[v % 10] += f[d];
        }
    }
    return g;
};
void dale() {
    int n, m; cin >> n >> m;
    vector<int> in(10);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        in[x]++;
    }
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                vector<ll> f(10);
                for (int d = 1; d < 10; d++) {
                    f[d] += dp[n][i][d] + dp[n][j][d] + dp[n][k][d];
                }
                int missing = 0, cara = -1, equal = 0;
                for (int d = 1; d < 10; d++) {
                    if (in[d] + 1 == f[d]) {
                        missing++;
                        cara = d;
                    } else if (in[d] == f[d]) equal++;
                }

                if (missing == 1 and equal == 8 and cara != -1) {
                    cout << cara << '\n';
                    return;
                }
            }
        }
    }
}
int main() {
    for (int i = 1; i < 10; i++) dp[0][i][i] = 1;
    for (int i = 0; i < 33; i++) {
        for (int d = 1; d < 10; d++) {
            dp[i + 1][d] = apply(dp[i][d]);
        }
    }
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}