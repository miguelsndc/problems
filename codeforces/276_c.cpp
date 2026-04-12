#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (auto &x: a) cin >> x;
	vector<int> d(n);
	while(q--) {
		int l, r; cin >> l >> r;
		--l, --r;
		d[l]++; 
		if (r + 1 < n) {
			d[r + 1]--;
		}
	}
	for (int i = 1; i < n; i++) {
		d[i] += d[i - 1];
	}
//	for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
//	for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];

	sort(a.begin(), a.end());
	sort(d.begin(), d.end());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (long long)d[i] * a[i];
	}
	cout << ans << '\n';
}
