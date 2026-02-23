#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
int n, k, a[maxn];

ll fexp(ll a, ll b, ll MOD){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a, ll p){ 
    return fexp(a, p - 2, mod);
}
ll fact[1000000]; 
ll comb(ll n, ll k, ll p) {
    if (k > n) return 0;
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}
void dale() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += a[i];
    }
    cnt0 = n - cnt1;
    // subsequences with exactly j ones
    ll ans = 0;
    for (int j = (k + 1)/2; j <= k; j++) {
        ans += comb(cnt1, j, mod) * comb(cnt0, k - j, mod) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
int main() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < 1000000; i++) (fact[i] = fact[i - 1] * i % mod) %= mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) dale();
}