#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
int n, k;
void gravidade(vector<string> &grid) {
    for (int c = 0; c < 10; c++) {
        for (int r = n - 1; r >= 0; r--) {
            int z = r;
            if (grid[z][c] > '0') {
                while (z + 1 < n and grid[z + 1][c] == '0') {
                    swap(grid[z][c], grid[z + 1][c]);
                    z++;
                }
            }
        }
    }
}
int get(char c) {
    return int(c - '0');
}
bool componentes(vector<string> &grid) {
    vector visited(n, vector<int>(10));
    vector<pii> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<pii> comp;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (visited[i][j] or grid[i][j] == '0') continue;
            int c = grid[i][j];
            visited[i][j] = true;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();
                comp.push_back({row, col});
                for (auto [dx, dy] : d) {
                    int nrow = row + dx;
                    int ncol = col + dy;
                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < 10 and !visited[nrow][ncol] and grid[nrow][ncol] == c) {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
            if (comp.size() >= k) {
                ok = true;
                for (auto [x, y] : comp) grid[x][y] = '0';
            }
            comp.clear();
        }
    }
    return ok;
}
void dale() {
    cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int ainda = componentes(grid);
    while (ainda) {
        gravidade(grid);
        ainda = componentes(grid);
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i]<<'\n';
    }
}
int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}