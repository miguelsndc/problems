#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// O(1)
ll fmul(ll a, ll b, ll M) {
    ll k = a * b - M * (long long)(1.L / M * a * b);
    return k + M * (k < 0) - M * (k >= (ll)M);
}

// O(log(e))
ll fexp(ll b, ll e, ll MOD) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = fmul(ans, b, MOD);
        b = fmul(b, b, MOD);
        e >>= 1;
    }
    return ans;
}

// ~ O(log n)
bool isPrime(ll n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ll bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
       s = __builtin_ctzll(n - 1), d = n >> s;

    for (ll base : bases) {
        ll p = fexp(base % n, d, n), i = s;

        while (p != 1 && p != n - 1 && base % n && i--)
            p = fmul(p, p, n);

        if (p != n - 1 && i != s) return false;
    }
    return true;
}
const int gap = 1500;
void dale() {
    ll n ; cin >> n;
    for (int i = 1; i <= gap; i++) {
        if (isPrime(i + n)) {
            cout << i + n << '\n';
            return;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}