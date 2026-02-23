#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
  int n, l, r; cin >> n >> l >> r;
  vector<int> a(n);
  for (auto &i: a) cin >> i;
  sort(a.begin(), a.end());
  vector<ll> pre(n + 1), suf(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = (pre[i] + a[i]);
  for (int i = n - 1; i >= 0; i--) suf[i] = (suf[i + 1] + a[i]);
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ll qtd = i - (n - i);
    ll s = suf[i ] - pre[i];
    ans = max(ans, min(qtd * l, qtd * r) + s);
  }
  for (int i = 0; i < n; i++) {
    ll qtd = i - (n - 1 - i);
    ll s = suf[i + 1] - pre[i];
    ans = max(ans, min(qtd * l, qtd * r) + s);
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int tt = 1; cin >> tt;
  while(tt--) dale();
}