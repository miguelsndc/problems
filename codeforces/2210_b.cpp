#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		set<int> s;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s.count(i)) s.erase(i);
			s.insert(a[i]);
			ans = max(ans, (int)s.size());
		}
		cout << max(ans, (int)s.size()) << '\n';
	}
}
