#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct UnionFind {
  vector<int> par, sz, min_el, max_el;
  UnionFind(int n) {
    par.assign(n, 0);
    sz.assign(n, 1);
    min_el.assign(n, 1);
    max_el.assign(n, 1);
    iota(par.begin(), par.end(), 0);
    iota(max_el.begin(), max_el.end(), 0);
    iota(min_el.begin(), min_el.end(), 0);
  }
  int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
  bool connected(int x, int y) {
    return find(x) == find(y);
  }
  int get_min(int x) {
    return min_el[find(x)];
  }
  int get_max(int x) {
    return max_el[find(x)];
  }
  bool unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) { return false; }
    if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
    sz[x_root] += sz[y_root];
    par[y_root] = x_root;
    min_el[x_root] = min(min_el[x_root], min_el[y_root]);
    max_el[x_root] = max(max_el[x_root], max_el[y_root]);
    return true;
  }
};
void dale() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  vector<pair<int, int>> tree;
  UnionFind dsu(n + 1);
  int mn = 1e9, mx = -1e9, comp = n;
  for (int i = 0; i < n; i++) {
    if (a[i] > mn and !dsu.connected(a[i], mn)) {
      dsu.unite(a[i], mn);
      comp--;
      tree.push_back({ mn, a[i] });
    }
    mn = min(mn, a[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] < mx and !dsu.connected(a[i], mx)) {
      comp--;
      dsu.unite(a[i], mx);
      tree.push_back({ a[i], mx });
    }
    mx = max(mx, a[i]);
  }
  int c = dsu.find(a[0]);
  for (int i = 1; i < n; i++) {
    if (!dsu.connected(c, a[i])) {
      if (dsu.get_min(c) < dsu.get_max(a[i])) {
        tree.push_back({ dsu.get_min(c), dsu.get_max(a[i]) });
      comp--;
        dsu.unite(c, a[i]);
      }
    }
  }
  if (comp > 1) {
    cout << "No\n";
    return;
  }
  assert(tree.size() == n - 1);
  cout << "Yes\n";
  for (auto& [x, y] : tree) cout << x << ' ' << y << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int tt = 1; cin >> tt;
  while (tt--) dale();
}