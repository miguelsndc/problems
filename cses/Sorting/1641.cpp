#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int t = x - (a[i].first + a[j].first);
			if (t < 0) continue;
			auto lb = lower_bound(a.begin(), a.end(), make_pair(t, INT_MIN)) - a.begin();
			auto ub = upper_bound(a.begin(), a.end(), make_pair(t, INT_MAX)) - a.begin();
			for (int u = lb; u < ub; u++) {
				if (u == i or u == j) continue;
				long long sum = a[i].first + a[j].first + a[u].first;
				cerr << i << ' ' << j << ' ' << u << ' ' << ' ' << a[u].second << '\n';
				cout << a[i].second + 1 << ' ' << a[j].second + 1 << ' ' << a[u].second + 1 << '\n';
				exit(0);
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
