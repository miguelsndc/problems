#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> grid(10);
	vector<vector<bool>> vis(10, vector<bool>(10));
	for (auto &x: grid) cin >> x;
	vector<int> qtd(5);
	bool ok = true;
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			if (grid[r][c] == '.' or vis[r][c]) continue;
			bool vert = false, hor = false;
			int szx = 1, szy = 1;
			int y = r, x = c;
			vis[y][x] = true;
			while(x + 1 < 10 and grid[y][x + 1] == '#') {
				vis[y][++x] = true;
				hor = true;
				szx++;
			}
			y = r, x = c;
			while(y + 1 < 10 and grid[y + 1][x] == '#') {
				vis[++y][x] = true;
				vert = true;
				szy++;
			}
			if (hor and vert) { 
				ok = false;
				break;
			}
			if (vert) {
				if (szy <= 4) {
					qtd[szy]++;
				} else {
					ok = false;
					break;
				}
			}
			else if (hor) {
				if (szx <= 4) {
					qtd[szx]++;
				} else {
					ok = false;
					break;
				}
			} else {
				qtd[1]++;
			}

			if (r - 1 >=0 and c - 1 >= 0 and grid[r-1][c-1] == '#') ok = false;
			if (r - 1 >=0 and c + 1 < 10 and grid[r-1][c+1] == '#') ok = false;
			if (r + 1 <10 and c - 1 >= 0 and grid[r+1][c-1] == '#') ok = false;
			if (r + 1 <10 and c + 1 < 10 and grid[r+1][c+1] == '#') ok = false;
		}
	}

	if (qtd[4] == 1 and qtd[3] == 2 and qtd[2] == 3 and qtd[1] == 4 and ok) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
