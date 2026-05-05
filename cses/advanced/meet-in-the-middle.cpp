#include <bits/stdc++.h>
using namespace std;
#define upper(v, x) upper_bound((v).begin(), (v).end(), (x))
#define lower(v, x) lower_bound((v).begin(), (v).end(), (x))
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x; cin >> n >> x;
	vector<int> t(n);
	for (auto &x: t) cin >> x;
	vector<int> left, right;
	int mid = n / 2;
	for (int i = 0; i < mid; i++) left.push_back(t[i]);
	for (int i = mid; i < n; i++) right.push_back(t[i]);
	auto gen = [&] (vector<int> &v) {
		vector<int> res;
		int sz = (int)v.size();
		for (int b = 1; b < (1 << sz); b++) {
			int sum = 0, ok = true;
			for (int j = 0; j < sz; j++) {
				if (!(b & (1 << j))) continue;
				sum += v[j];
				if (sum > x) {
					ok = false; break;
				}
			}
			if (ok) {
				res.push_back(sum);
			}
		}
		return res;
	};
	vector<int> v1 = gen(left);
	vector<int> v2 = gen(right);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long ans = 0;
	ans += upper(v1, x) - lower(v1, x);
	ans += upper(v2, x) - lower(v2, x);

	for (int y: v1) {
		ans += upper(v2, x - y) - lower(v2, x - y);
	}
	cout << ans << '\n';
}

