#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct BIT{
    int n;
    vector<ll> bit;
    BIT(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum [0..pos] (0-based)
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
void dale() {
  int n, k; cin >> n >> k;
  vector<vector<int>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    tree[--u].push_back(--v);
    tree[v].push_back(u);
  }
  BIT bit(n + 1);
  vector<int> sz(n);
  function<int(int, int)> get_sz = [&](int u, int p) -> int {
    sz[u] = 1;
    for (int v : tree[u]) {
      if (v == p) continue;
      sz[u] += get_sz(v, u);
    }
    return sz[u];
    };
  get_sz(0, -1);
  ll ans = 0;
  for (int i = 0; i < n; i++) bit.add(sz[i], 1);
  function<void(int, int)> get_ans = [&](int u, int p) {
    assert(bit.sum(n) == n);
    ans += bit.sum(n) - bit.sum(k - 1);
    for (int v : tree[u]) {
      if (v == p) continue;
      int su = sz[u], sv = sz[v];
      bit.add(su, -1);
      bit.add(sv, -1);
      bit.add(n, 1);
      bit.add(n - sv, 1);
      sz[v] = n;
      sz[u] = n - sv;
      get_ans(v, u);
      bit.add(su, 1);
      bit.add(sv, 1);
      bit.add(n, -1);
      bit.add(n - sv, -1);
      sz[v] = sv;
      sz[u] = su;
    }
    };
  get_ans(0, -1);
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int tt = 1; cin >> tt;
  while (tt--) dale();
}