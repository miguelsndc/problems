#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    int tot = 0;
    for (string& s : grid) {
        cin >> s;
        tot += count(s.begin(), s.end(), '.');
    }
    int keep = tot - k;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    auto pode = [&](int ni, int nj) {
        return ni >= 0 and ni < n and nj >= 0 and nj < m and
               grid[ni][nj] == '.';
    };
    vector vis(n, vector<bool>(m));
    int cnt = 0;
    auto dfs = [&](auto&& self, int i, int j) -> void {
        if (cnt >= keep) return;
        cnt++;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (pode(ni, nj) and !vis[ni][nj]) {
                self(self, ni, nj);
                ;
            }
        };
        int startx, starty;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(dfs, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and grid[i][j] == '.') grid[i][j] = 'X';
        }
    }
    for (auto& s : grid) cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}