#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    while((cin >> s >> t)) {
        vector dp(sz(s), vector<ll>(sz(t), -1));
        auto solve = [&] (auto &&self, int i, int j) -> ll {
            if (j == sz(t)) return 1;
            if (i == sz(s)) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            ll ans = 0;
            if (s[i] == t[j]) ans = (ans + self(self, i + 1, j + 1)) % mod;
            ans = (ans + self(self, i + 1, j)) % mod;
            return dp[i][j] = ans;
        };
        cout << solve(solve, 0, 0) << '\n';
    }
}