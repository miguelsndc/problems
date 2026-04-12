#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> ps(n + 1);
		for (int i = 0; i < n; i++) {
			ps[i + 1] = ps[i] + (int)(s[i] - '0');
		}
		map<int, int> mp;
		mp[0] = 1;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += mp[ps[i] - i];
			mp[ps[i] - i]++;
		}
		cout << ans << '\n';
	}
}
