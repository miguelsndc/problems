#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k; cin >> k;
    vector<ll> dp(k + 1), ps(k + 2);
    dp[1] = ps[1] = 1;
    for (int i = 2; i <= k; i++) {
        ps[i] = ps[i - 1];
        dp[i] = (ps[i] - ps[(i + 1) / 2 - 1] + mod) % mod;
        ps[i] = (ps[i] + dp[i]) % mod;
    }
    cout << dp[k] << '\n';
}