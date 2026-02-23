#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
void dale() {
  int n, k, x; cin >> n >> k >> x;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(a.begin(), a.end());
  vector<ii> intervalos{{0, x + 1}};
  int l = 1, r = x + 1, aqui = 0;
  while (l <= r) {
    int d = l + (r - l) / 2;
    vector<ii> liberado;
    int cur = 0, ok = 0;
    for (int i = 0; i < n; i++) {
      int left = max(0, a[i] - (d - 1));
      int right = min(x, a[i] + d - 1);
      if (left > cur) {
        ok += left - cur;
        liberado.push_back({cur, left});
      }
      cur = max(cur, right + 1);
    }
    if (cur <= x) {
      ok += x + 1 - cur;
      liberado.push_back({cur, x + 1});
    }
    if (ok >= k) {
      l = d + 1;
      if (d > aqui) {
        aqui = d;
        intervalos = liberado;
      }
    }
    else {
      r = d - 1;
    }
  }
  vector<int> ans;
  for (auto& [a, f] : intervalos) {
    for (int x = a; x < f and ans.size() < k; x++) {
      ans.push_back(x);
    }
  }

  for (int x : ans) cout << x << ' ';
  cout << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int tt = 1; cin >> tt;
  while (tt--) dale();
}