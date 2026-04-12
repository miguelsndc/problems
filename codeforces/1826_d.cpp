#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i] + i;
		c[i] = a[i] - i;
	}
	vector<int> pre(n), suf(n);
	pre[0] = b[0]; suf[n - 1] = c[n - 1];
	for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], b[i]);
	for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], c[i]);
	long long ans = 0;
	for (int i = 1; i + 1< n; i++) {
		ans = max(ans, (long long) pre[i - 1] + a[i] + suf[i + 1]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1; cin >> tt;
	while(tt--) solve();
}
