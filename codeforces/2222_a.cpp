#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x: a) cin >> x;
		vector<int> coins(n);
		for (int i = 0; i < n; i++) {
			coins[i] = 100 / a[i];
		}
		vector<int> reach(100 * n + 1);
		reach[0] = 1;
		for (int c: coins) {
			for (int v = c; v <= 100 * n; v++) {
				reach[v] |= reach[v - c];
			}
		}
		bool all = true;
		for (int i = 0; i <= 100 * n; i++) {
			all &= reach[i];
		}
		cout << (all ? "Yes\n": "No\n");
	}
}
