#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
	return a / __gcd(a, b) * b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (auto &x: a) cin >> x;
		for (auto &x: b) cin >> x;
		int op = 0;
		for (int i = 0; i < n; i++) {
			int l = 1, r = 1;
			if (i - 1 >= 0) {
				l = __gcd(a[i], a[i - 1]);
			}
			if (i + 1 < n) {
				r = __gcd(a[i], a[i + 1]);
			}
			if (a[i] > lcm(l, r)) {
				a[i] = lcm(l, r);
				op++;
			}
		}
		cout << op << '\n';
	}
}
