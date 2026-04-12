#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x: a) cin >> x;

	vector<long long> pre(n + 1), suf(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i]; 
	}
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = (long long)(n - i) * a[i] + suf[i + 1];
	}

	auto sum = [&] (int start, int end) {
		return suf[start] - suf[end] - (n - end) * (pre[end] - pre[start]);
	};
	vector<long long> cnt(n + 1), cnt_ps(n + 1);
	for (int i = 0; i < n; i++) cnt[i + 1] = cnt[i] + n - i;
	for (int i = 0; i < n; i++) cnt_ps[i + 1] = cnt_ps[i] + suf[i];

	auto query = [&] (long long prefix) {
		int before = (int)(upper_bound(cnt.begin(), cnt.end(), prefix) - cnt.begin()) - 1; 
		int extra = prefix - cnt[before];
		return cnt_ps[before] + sum(before, before + extra);
	};

	int Q; cin >> Q;
	while(Q--) {
		long long L, R;
		cin >> L >> R;
		cout << query(R) - query(L - 1) << '\n';
	}

}
