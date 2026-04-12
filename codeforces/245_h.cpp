#include <bits/stdc++.h>
using namespace std;
const int ms = 5005;
int dp[ms][ms], pre[ms][ms];
string s;
/*
	se l == r palindromo 
	se r - l == 1 e s[l] == s[r] palindromo
	se nao s[l] == s[r] e f(l + 1, r - 1) for palindromo
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> s;
	int n = (int)(s.size());
	for (int i = 0; i < n; i++) dp[i][i] = 1;

	for (int len = 2; len <= n; len++) {
		for (int l = 0; l + len - 1 < n; l++) {
			int r = l + len - 1;
			if (s[l] == s[r]) {
				if (len == 2) dp[l][r] = 1;
				else dp[l][r] = dp[l + 1][r - 1];
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int ps2d = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			pre[i][j] = ps2d + dp[i - 1][j - 1];
		}
	}


	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		cout << pre[r][r] - pre[l - 1][r] - pre[r][l - 1] + pre[l - 1][l - 1] << '\n';
	}
}
