#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n; cin >> n;
	string s; cin >> s;
	vector<int> ab(n);
	vector<int> ac(n);
	vector<int> bc(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') ab[i] = 1;
		else if (s[i] == 'B') ab[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') ac[i] = 1;
		else if (s[i] == 'C') ac[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') bc[i] = 1;
		else if (s[i] == 'C') bc[i] = -1;
	}
	auto cnt_zeros = [&] (vector<int> &v) {
		long long ans = 0, ps = 0;
		map<int,int> mp;
		mp[0] = 1;
		for (int i = 0; i < n; i++) {
			ps += v[i];
			ans += mp[ps];
			mp[ps]++;
		}
		return ans;
	};
	/* ai - bi, ai - ci */
	vector<int> ps(3);
	map<pair<int,int>, int> mp;
	mp[{0,0}] = 1;
	long long all = 0;
	for (int i = 0; i < n; i++) {
		int v = (int)(s[i] - 'A');
		ps[v]++;
		pair<int,int> target = {ps[0] - ps[1], ps[0] - ps[2]};
		all += mp[target];
		mp[target]++;
	}
	long long cur = cnt_zeros(ab) + cnt_zeros(bc) + cnt_zeros(ac);
	cout << n * (n + 1) / 2 - cur + 2 * all;
}

