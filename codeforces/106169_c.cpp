#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mxn = 2e7 + 5;
int primo[mxn], cnt[mxn], lpf[mxn];
vector<int> primos;
void crivo() {
    fill(primo, primo + mxn, true);
    iota(lpf, lpf + mxn, 0);
    primo[0] = primo[1] = false;
    for (int i = 2; i < mxn; i++) {
        if (primo[i]) {
            primos.push_back(i);
            lpf[i] = i;
            for (ll j = 2 * i; j < mxn; j += i) {
                primo[j] = false;
                lpf[j] = i;
            }
        }
    }
}
vector<int> sieve_factorization(int n) {
    vector<int> primes;
    while (n > 1) {
        primes.push_back(lpf[n]);
        n /= lpf[n];
    }
    return primes;
}

void dale() {
    crivo();
    ll n;
    cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     if ((i & 1) and primo[cnt[i]] and (cnt[i] & 1)) {
    //         cout << i << ' ' << cnt[i] << " : 1 ";
    //         for (int x: sieve_factorization(i)) {
    //             cout << x << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
    ll ans = 0;
    for (ll x : primos) {
        if (x == 2) continue;
        if (x * x > n) break;
        ll k = x * x, pw = 2;
        while (k <= n) {
            if (pw + 1 < mxn and primo[pw + 1]) { ans++; }
            if (k > n / (x * x)) break;
            k *= (x * x);
            pw += 2;
        }
    }
    cout << ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}