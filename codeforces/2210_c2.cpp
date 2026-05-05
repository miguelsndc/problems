#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
const int inf = 1e18;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		for (auto &x: a) cin >> x;
		for (auto &x: b) cin >> x;
		for (int i = 0; i < n; i++) {
			if (i == 0) c[i] = gcd(a[i], a[i + 1]);
			else if (i == n - 1) c[i] = gcd(a[i], a[i - 1]);
			else c[i] = lcm(gcd(a[i], a[i-1]), gcd(a[i], a[i+1]));
			if (c[i] > b[i]) c[i] = a[i];
		}
		int L = (int)(primes.size());
		vector dp(n, vector<int>(L, -inf));
		for (int i = 0; i < L; i++) {
			if (i == 0) {
				dp[0][0] = (c[0] != a[0]);
				continue;
			}
			int val = c[0] * primes[i];
			if (val <= b[0] and gcd(val, c[1]) == gcd(a[0], a[1]) and val != a[0]) dp[0][i] = 1;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < L; j++) {
				for (int k = 0; k < L; k++) {
					if (j == 0) {
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + (int)(c[i] != a[i]));
						continue;
					}
					int v1 = c[i] * primes[j];
					int v2 = c[i - 1] * primes[k];
					if (v1 <= b[i] and gcd(v1, v2) == gcd(a[i], a[i-1]) and v1 != a[i]) {
						if (i < n - 1) {
							if (gcd(v1,c[i+1]) == gcd(a[i], a[i+1])){
								dp[i][j] = max(dp[i][j], dp[i-1][k]+1);
							}
						} else {
							dp[n-1][j] = max(dp[n-1][j], dp[n-2][k]+1);
						}
					}
				}
			}
		}
		cout << max(0ll, *max_element(dp[n-1].begin(), dp[n-1].end())) << '\n';
	}
}

