#include <bits/stdc++.h>
using namespace std;
const int ms = 1e5 + 5, MXNODES = 1e7;
int L[MXNODES], R[MXNODES], roots[ms], val[MXNODES], a[ms], nodecnt = 0, n;
int update(int p, int l, int r, int pos) {
	int id = ++nodecnt;
	L[id] = L[p]; R[id] = R[p];
	val[id] = val[p] + 1;
	if (l == r) return id;
	int m = (l + r) / 2;
	if (pos <= m) L[id] = update(L[p], l, m, pos);
	else R[id] = update(R[p], m + 1, r, pos);
	return id;
}
int query(int rootl, int rootr, int l, int r, int k) {
	if (l == r) return l;
	int m = (l + r) / 2;
	int count_left = val[L[rootr]] - val[L[rootl]];
	if (k <= count_left) return query(L[rootl], L[rootr], l, m, k);
	return query(R[rootl], R[rootr], m + 1, r, k - count_left);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	vector<int> b;
	for (int i = 1; i <= n; i++) cin >> a[i], b.push_back(a[i]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	auto get = [&] (int x) {
		return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
	};
	map<int, int> rev;
	for (int i = 1; i <= n; i++) {
		rev[get(a[i])] = a[i];
	}
	roots[0] = 0;
	int mx = (int)b.size();
	for (int i = 1; i <= n; i++) {
		roots[i] = update(roots[i - 1], 1, mx, get(a[i]));
	}
	while(m--) {
		int l, r, k; cin >> l >> r >> k;
		int v = query(roots[l - 1], roots[r], 1, mx, k);
		cout << rev[v] << '\n';
	}
}

