#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n); 
	for (auto &x: a) cin >> x;
	int mid = n / 2;
	vector<int> L, R;
	for (int i = 0; i < mid; i++) L.push_back(a[i]);
	for (int i = mid; i < n; i++) R.push_back(a[i]);
	auto gen = [&] (vector<int> &sums) {
		int sz = (int)sums.size();
		vector<int> res;
		for (int mask = 0; mask < (1 << sz); mask++) {
			long long sum = 0;
			for (int i = 0; i < sz; i++) {
				if (!(mask & (1 << i))) continue;
				sum += sums[i];
			}
			res.push_back(sum % m);
		}
		return res;
	};
	vector<int> L_res = gen(L), R_res = gen(R);
	sort(R_res.begin(), R_res.end());
	int ml = *max_element(L_res.begin(), L_res.end());
	int mr = *max_element(R_res.begin(), R_res.end());
	int ans = max(ml, mr);
	for (int x: L_res) {
		int idx = (int)(upper_bound(R_res.begin(), R_res.end(), m - 1 - x) - R_res.begin()) - 1;
		if (idx < 0) {
			continue;
		}
		ans = max(ans, x + R_res[idx]);
	}
	cout << ans;
}
