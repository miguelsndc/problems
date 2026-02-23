#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

vector<ll> FWHT(char oper, vector<ll> a, bool inv = false) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                ll u = a[i + j], v = a[i + j + len];
                if (oper == '^') {
                    a[i + j] = (u + v) % mod;
                    a[i + j + len] = (u - v + mod) % mod;
                } else if (oper == '|') {
                    if (!inv) a[i + j + len] = u + v;
                    else a[i + j + len] = v - u;
                } else if (oper == '&') {
                    if (!inv) a[i + j] = u + v;
                    else a[i + j] = u - v;
                }
            }
        }
    }
    if (oper == '^' && inv) {
        ll inv_n = fexp(n, mod - 2);
        for (int i = 0; i < n; i++) a[i] = a[i] * inv_n % mod;
    }
    return a;
}
vector<ll> multiply(char oper, vector<ll> a, vector<ll> b) {
    int n = 1;
    while (n < (int)max(a.size(), b.size())) n <<= 1;
    a.resize(n);
    b.resize(n);
    a = FWHT(oper, a);
    b = FWHT(oper, b);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) ans[i] = a[i] * b[i]; 
    ans = FWHT(oper, ans, true);
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<ll> f(1 << 22);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }

    vector<ll> fw = multiply('&', f, f);

    vector<ll> pairs(1 << 22);
    for (int i = 0; i < (1 << 22); i++) {
        pairs[i] = (fw[i] - f[i]) / 2;
    }

    ll ans = 0;
    for (int m = 0; m < (1 << 22); m++) {
        ans = (ans + 1LL * pairs[m] % mod * m % mod) % mod;
    }

    ans = ans * fexp(2, n - 2) % mod;
    cout << ans % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
