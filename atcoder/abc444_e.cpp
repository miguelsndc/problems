#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  set<ll> s({(ll)-1e9, (ll)2e9});
  ll ans = 0;
  int r = 0;
  for (int l = 0; l < n; l++) {
    while (r < n) {
      auto it = s.lower_bound(a[r]);
      if (*it - a[r] < d) break;
      it--;
      if (a[r] - *it < d) break;
      s.insert(a[r++]);
    }
    ans += r - l;
    s.erase(a[l]);
  }
  cout << ans << '\n';
}