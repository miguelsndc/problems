#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x: a) cin >> x;
	vector<int> pre(n + 1), suf(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = __gcd(pre[i], a[i]);
	}	
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = __gcd(suf[i + 1], a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int pre_gcd = pre[i];
		int suf_gcd = suf[i + 1];
		ans = max(ans, __gcd(pre_gcd, suf_gcd));
	}
	cout << ans;
}
