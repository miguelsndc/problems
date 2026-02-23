#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
const int mod = 1e9 + 7;
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a){ 
    return fexp(a, mod - 2);
}
const int mxn = 1e5 + 10;
ll fact[mxn];
ll comb(ll n, ll k) {
    if (k > n) return 0;
    return ((fact[n] * inv(fact[k]) % mod) * inv(fact[n - k])) % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    fact[0] = 1;
    for (ll i = 1; i < mxn; i++) fact[i] = (i * fact[i - 1]) % mod;
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        ll base = 2;
        ll extra = (fact[a] * inv(fact[b + 1])) % mod;
        cout << (base * extra) % mod << '\n';
    }
}