#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void dale() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string& s : grid) cin >> s;
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<int> sizes;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    auto ok = [&](int i, int j) -> bool {
        return i >= 0 and i < n and j >= 0 and j < m and !visited[i][j] and grid[i][j] == '#';
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] or grid[i][j] == '~') continue;
            visited[i][j] = true;
            queue<pii> q;
            q.push({i, j});
            int sz = 0;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                sz++;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dy[k];
                    int nc = c + dx[k];
                    if (ok(nr, nc)) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            sizes.push_back(sz);
        }
    }
    ll denom = n * m;
    ll num = 0;
    for (ll sz : sizes) {
        num += sz * sz;
    }

    ll g = __gcd(denom, num);

    if (num % denom == 0) {
        cout << num / denom << '\n';
    } else {
        cout << num / g << " / " << denom / g << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}