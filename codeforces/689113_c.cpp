#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>

const int MOD1 = 188'888'881;
const int MOD2 = 1e9 + 7;
const int base = 137, MAXN = 2e5 + 5;

ll pow1[MAXN], pow2[MAXN];
void calc_pow() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow1[i] = (pow1[i - 1] * base) % MOD1;
        pow2[i] = (pow2[i - 1] * base) % MOD2;
    }
}

struct Hashing {
    vector<pii> pref;
    Hashing(string& s) {
        pref = vector<pii>(s.size() + 1, { 0, 0 });
        for (int i = 0; i < s.size(); i++) {
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1;
            pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
        }
    }
    ll operator()(int a, int b) {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return (h1 << 32) | h2;
    }
};

void slve() {
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)(t.size());
    vector<int> w(n);
    for (auto& x : w) cin >> x;

    string ext = "";
    while (ext.size() < n + m) ext += s;
    Hashing hash_ext(ext), hash_t(t);
    ll hashtotal = hash_t(0, m - 1);
    vector<int> next(n, -1), valido(n);
    for (int i = 0; i < n; i++) {
        if (hash_ext(i, i + m - 1) == hashtotal) {
            valido[i] = true;
            next[i] = (i + m) % n;
        }
    }
    vector<int> cor(n);
    vector<ll> dp(n);
    bool tem_ciclo = false;
    auto dfs = [&](auto& self, int u) -> void {
        cor[u] = 1;
        dp[u] = w[u];
        if (next[u] == -1 or !valido[next[u]]) {
            cor[u] = 2;
            return;
        }
        if (cor[next[u]] == 1) {
            tem_ciclo = true;
            return;
        } else {
            if (cor[next[u]] == 0) self(self, next[u]);
            dp[u] += dp[next[u]];
        }
        cor[u] = 2;
    };

    for (int i = 0; i < n; i++) {
        if (next[i] != -1) {
            dfs(dfs, i);
            if (tem_ciclo) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    calc_pow();
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}