#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (string& s : grid) cin >> s;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    auto no_grid = [&](int i, int j) {
        return i >= 0 and i < h and j >= 0 and j < w;
    };
    auto conta = [&](int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (no_grid(nx, ny) and grid[nx][ny] == '#') {
                cnt++;
            }
        }
        return cnt;
    };

    vector<pii> T;
    for (int i = 0; i < h * w; i++) {
        if (i == 0) {
            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (grid[x][y] == '.' and conta(x, y) == 1) {
                        T.push_back({x, y});
                    }
                }
            }
        } else {
            vector<pii> nt;
            for (auto [x, y] : T) {
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (no_grid(nx, ny) and grid[nx][ny] == '.' and conta(nx, ny) == 1) {
                        nt.push_back({nx, ny});
                    }
                }
            }
            T = nt;
        }
        if (T.size() == 0) {
            break;
        } else
            for (auto [x, y] : T) grid[x][y] = '#';
    }
    int ans = 0;
    for (string& s : grid)
        for (char c : s) ans += (c == '#');
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}