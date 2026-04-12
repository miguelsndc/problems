#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> cities(n), towers(m);
	for (auto &x: cities) cin >> x;
	for (auto &x: towers) cin >> x;
	int j = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int min_dist = abs(cities[i] - towers[j]);
		while (j + 1 < m and abs(cities[i] - towers[j + 1]) <= min_dist) {
			min_dist = abs(cities[i] - towers[j + 1]);
			j++;
		}
		ans = max(ans, min_dist);
	}
	cout << ans << '\n';
}
