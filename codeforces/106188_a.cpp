#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    ll ans = 0, p = 1;
    for (ll x: a) {
        if (x == 0) {
            if (p > 1) ans += p % mod;
            p = 1;
        } else {
            p *= x % mod;
            p %= mod;
        }
        ans %= mod;
    }
    if (p > 1) ans += p % mod;
    cout << ans % mod << '\n';
}