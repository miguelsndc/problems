#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

#include <vector>

template<int mod, typename t = long long>
struct combo {
    vector<t> f, inv_f;
    combo(int n) : f(n + 1, 1), inv_f(n + 1, 1) {
        for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i % mod;
        inv_f[n] = pow(f[n], mod - 2);
        for (int i = n - 1; i > 0; --i) inv_f[i] = inv_f[i + 1] * (i + 1) % mod;
    }
    t pow(t b, t e) const {
        t r = 1;
        for (b %= mod; e; e >>= 1, b = b * b % mod) 
            if (e & 1) r = r * b % mod;
        return r;
    }
    t inv(t n) const { return pow(n, mod - 2); }
    t nck(int n, int k) const {
        return (k < 0 || k > n) ? 0 : f[n] * inv_f[k] % mod * inv_f[n - k] % mod;
    }
    t npk(int n, int k) const {
        return (k < 0 || k > n) ? 0 : f[n] * inv_f[n - k] % mod;
    }
    t stars(int n, int k) const {
        return (n == 0 && k == 0) ? 1 : (k == 0 ? 0 : nck(n + k - 1, k - 1));
    }
    t cat(int n) const {
        return n < 0 ? 0 : nck(2 * n, n) * inv(n + 1) % mod;
    }
};

const int mod = 998244353, ms = 3e5 + 10;
combo<mod> comb(ms);
vector<int> sieve(ms, true), spf(ms);
void precalc() {
    sieve[0] = sieve[1] = false;
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i < ms; i++) {
        if (sieve[i]) {
            for (int j = i + i; j < ms; j += i) {
                sieve[i] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
