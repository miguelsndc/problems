#include <bits/stdc++.h>
using namespace std;
const int ms = 405;
int mat[ms][ms], rot[2 * ms][2 * ms], era[2*ms][2*ms];
long long pre[2*ms][2*ms];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rot[i + j][n - 1 - i + j] = mat[i][j];
			era[i + j + 1][n - i + j] = true;
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + rot[i - 1][j - 1];
		}
	}

	auto query = [&] (int r1, int c1, int r2, int c2) {
		return pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1];
	};

	long long ans = 0;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			if (!era[i][j]) continue;
			int r1 = max(1, i - k);
			int c1 = max(1, j - k);
			int r2 = min(n * 2, i + k);
			int c2 = min(n * 2, j + k);
			long long val = query(r1, c1, r2, c2);
			ans = max(ans, val);
		}
	}
	cout << ans << '\n';
}
