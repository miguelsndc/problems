#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	/*
	0 - derrota
	1 - vitoria
	 */
	vector<int> dp(n + 1), moves(k);
	for (int i = 0; i < k; i++) cin >> moves[i];
	for (int sz = 1; sz <= n; sz++) {
		for (int x: moves) {
			if (sz >= x) {
				dp[sz] |= !dp[sz - x];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (dp[i] ? "W": "L");
	}
}

