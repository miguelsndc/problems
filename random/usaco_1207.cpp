#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
vector<pii> subs_L[30], subs_R[30];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long xq, yq; cin >> xq >> yq;
	vector<pii> pt(n);
	for (auto &[x, y]: pt) cin >> x >> y;
	int mid = n / 2;
	vector<pii> pts_L, pts_R;
	for (int i = 0; i < mid; i++) pts_L.push_back(pt[i]);
	for (int i = mid; i < n; i++) pts_R.push_back(pt[i]);
	auto generate = [&] (vector<pii> &pts, vector<pii>*subs) {
		int sz = (int)pts.size();
		for (int mask = 0; mask < (1 << sz); mask++) {
			int idx = __builtin_popcount(mask);
			pii res = {0, 0};
			for (int i = 0; i < sz; i++) {
				if (mask & (1 << i)) {
					res.first += pts[i].first;
					res.second += pts[i].second;
				}
			}
			subs[idx].push_back(res);
		}
	};
	generate(pts_L, subs_L);
	generate(pts_R, subs_R);
	for (int i = 1; i < 30; i++) {
		sort(subs_L[i].begin(), subs_L[i].end());
		sort(subs_R[i].begin(), subs_R[i].end());
	}
	vector<long long> ans(41);

	for (int i = 1; i < 21; i++) {
		auto lb = lower_bound(subs_L[i].begin(), subs_L[i].end(), make_pair(xq, yq));
		auto ub = upper_bound(subs_L[i].begin(), subs_L[i].end(), make_pair(xq, yq));
		ans[i] += ub - lb;
	}

	for (int i = 1; i < 21; i++) {
		auto lb = lower_bound(subs_R[i].begin(), subs_R[i].end(), make_pair(xq, yq));
		auto ub = upper_bound(subs_R[i].begin(), subs_R[i].end(), make_pair(xq, yq));
		ans[i] += ub - lb;
	}

	for (int b = 1; b < 21; b++) {
		for (auto &[x, y]: subs_L[b]) {
			for (int c = 1; c < 21; c++) {
				auto lb = lower_bound(subs_R[c].begin(), subs_R[c].end(), make_pair(xq - x, yq - y));
				auto ub = upper_bound(subs_R[c].begin(), subs_R[c].end(), make_pair(xq - x, yq - y));
				ans[b + c] += ub - lb;
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
