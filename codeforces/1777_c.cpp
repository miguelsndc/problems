#include <bits/stdc++.h>
using namespace std;
const int ms = 1e5 + 10;
vector<int> factors[ms];
void sieve() {
	for (int i = 1; i < ms; i++) {
		for (int j = i; j < ms; j += i) {
			factors[j].push_back(i);
		}
	}
}
int main () {
	sieve();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), freq(m + 1);
        int covered = 0;
		for (auto &x: a) cin >> x;
		sort(a.begin(), a.end());
		auto add = [&] (int x) {
			for (int f: factors[x]) {
				if (f > m) break;
                if (freq[f] == 0) covered++;
                freq[f]++;
			}
		};
		auto remove = [&] (int x) {
			for (int f: factors[x]) {
				if (f > m) break;
                if (freq[f] == 1) covered--;    
                freq[f]--;
			}
		};
		int r = 0, ans = 1e9;
		for (int l = 0; l < n; l++) {
			while (r < n and covered < m) {
				add(a[r++]);
			}
			if (covered == m) ans = min(ans, a[r - 1] - a[l]);
			remove(a[l]);
		}
		cout << (ans == (int)1e9 ? -1 : ans) << '\n';
	}
}
