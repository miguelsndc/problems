#include <bits/stdc++.h>
using namespace std;
int n, m, mid; long long k; 
long long grid[21][21];
// quero o xor ate grid[r][c][xor] = cnt
map<long long, long long> fw_dp[21][21];
map<long long, long long> bw_dp[21][21];
void dfs_fw(int r, int c, long long xorsum) {
	if (r + c == mid) {
		fw_dp[r][c][xorsum]++;
		return;
	}
	if (r + 1 < n) {
		dfs_fw(r + 1, c, xorsum ^ grid[r + 1][c]);
	}
	if (c + 1) {
		dfs_fw(r, c + 1, xorsum ^ grid[r][c + 1]);
	}
}
void dfs_bw(int r, int c, long long xorsum) {
	if (r + c == mid) {
		bw_dp[r][c][xorsum]++;
		return;
	}
	if (r - 1 >= 0) {
		dfs_bw(r - 1, c, xorsum ^ grid[r - 1][c]);
	}
	if (c - 1 >= 0) {
		dfs_bw(r, c - 1, xorsum ^ grid[r][c - 1]);
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m; cin >> k;
	mid = (n + m - 2) / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

	dfs_fw(0, 0, grid[0][0]);
	dfs_bw(n - 1, m - 1, grid[n - 1][m - 1]);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j != mid) continue;
			for (auto &[xorsum, cnt]: fw_dp[i][j]) {
				// bw[i][j] == k ^ grid[i][j] ^ fw[i][j];
				long long quero = k ^ grid[i][j] ^ xorsum;
				ans += cnt * bw_dp[i][j][quero];
			}
		}
	}
	cout << ans << '\n';
}
