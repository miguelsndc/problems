#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
template <typename T> class LazySegtree {
  private:
	const int sz;
	vector<T> tree;
	vector<T> lazy;
	void apply(int v, int len, T val) {
		tree[v] = val * len;
		lazy[v] = val;
	}
	void push_down(int v, int l, int r) {
		if (lazy[v] != -1) {
			int m = (l + r) / 2;
			apply(2 * v, m - l + 1, lazy[v]);
			apply(2 * v + 1, r - m, lazy[v]);
			lazy[v] = -1;
		}
	}
 
	void range_set(int v, int l, int r, int ql, int qr, T val) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(v, r - l + 1, val);
		} else {
			push_down(v, l, r);
			int m = (l + r) / 2;
			range_set(2 * v, l, m, ql, qr, val);
			range_set(2 * v + 1, m + 1, r, ql, qr, val);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}
 
	T range_sum(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return 0; }
		if (ql <= l && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;
		return range_sum(2 * v, l, m, ql, qr) + range_sum(2 * v + 1, m + 1, r, ql, qr);
	}
 
  public:
	LazySegtree(int n) : sz(n), tree(4 * n), lazy(4 * n, -1) {}
	void range_set(int ql, int qr, T val) { range_set(1, 0, sz - 1, ql, qr, val); }
	T range_sum(int ql, int qr) { return range_sum(1, 0, sz - 1, ql, qr); }
};
void solve() {
    int n; cin >> n;
    vector<int> v;
    vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        v.push_back(l);
        v.push_back(r);
        a[i] = {l, r};
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    auto get = [&] (int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    };
    int active = 0;
    LazySegtree<int> seg(v.size());
    for (int i = n - 1; i >= 0; i--) {
        int l = get(a[i].first);
        int r = get(a[i].second);
        if (seg.range_sum(l, r) < (r - l + 1)) {
            active++;
            seg.range_set(l, r, 1);
        }
    }
    cout << active << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while(tt--) solve();
}