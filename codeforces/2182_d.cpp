#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll fexp(ll a, ll b, ll MOD) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ans;
}
ll inv(ll a, ll p) {
  return fexp(a, p - 2, mod);
}
const int mxn = 10000;
ll fact[mxn];
ll comb(ll n, ll k) {
  if (k < 0 or k > n) return 0; 
  return ((fact[n] * inv(fact[k], mod) % mod) * inv(fact[n - k], mod)) % mod;
}
void dale() {
  int n; cin >> n;
  int s = 0;
  vector<int> A(n + 1);
  for (int i = 0; i <= n; i++) cin >> A[i], s += A[i];
  rotate(A.begin(), A.begin() + 1, A.end());
  int extra = s % n;
  int b = s / n;
  int big = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > b + 1) {
      cout << 0 << '\n';
      return;
    } else if (A[i] == b + 1) big++;
  }
  ll x = (comb(extra, big)) * fact[big] % mod;
  ll ans = (x * fact[n - big]) % mod;
  cout << ans << "\n";
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < mxn; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  cin.tie(0)->sync_with_stdio(false);
  int tt = 1; cin >> tt;
  while (tt--) dale();
}