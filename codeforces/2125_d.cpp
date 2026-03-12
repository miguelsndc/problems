#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 998244353, mxn = 2e5 + 10;
int n, m;
ll L[mxn], R[mxn], P[mxn], Q[mxn], dp[mxn], pre[mxn];
vector<ll> start[mxn];
ll fexp(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a) { return fexp(a, mod - 2, mod); }
ll f(int x) {
    if (x > m) return 1;
    if (x <= m and sz(start[x]) == 0) return 0;
    if (dp[x] != -1) return dp[x];
    ll ans = 0;
    for (int id : start[x]) {
       ll w = P[id] * inv((Q[id] - P[id] + mod) % mod) % mod;
        ans = (ans + w * f(R[id] + 1)) % mod;
    }
    return dp[x] = ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i] >> P[i] >> Q[i];
        start[L[i]].push_back(i);
    }
    pre[0] = 1;
    for (int i = 1; i <= m; i++) {
        ll prod = 1;
        for (int id : start[i]) {
            ll pnot = ((Q[id] - P[id] + mod) % mod) * inv(Q[id]) % mod;
            prod = (prod * pnot) % mod;
        }
        pre[i] = (pre[i - 1] * prod) % mod;
    }
    cout << f(1) * pre[m] % mod << '\n';
}
