#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (auto &x: a) cin >> x;
	int l = 0; long long sum = 0, ans = 0;
	for (int r = 0; r < n; r++) {
		sum += a[r];
		while (l < n and sum > x) {
			sum -= a[l++];
		}
		ans += (sum == x);
	}
	cout << ans << '\n';
}
