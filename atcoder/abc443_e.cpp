#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
void bop()
{
    int n, c;
    cin >> n >> c;
    vector<string> g(n);
    for (auto& s : g)
        cin >> s;
    int sr = n - 1, sc = c - 1;
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<int> cfirst(n);
    vector<queue<int>> cfirst_wall(n);
    for (int c = 0; c < n; c++) {
        for (int r = n - 1; r >= 0; r--) {
            if (g[r][c] == '#') {
                cfirst_wall[c].push(r);
            }
        }
    }
    vis[sr][sc] = true;
    vector<int> frontier { sc };
    for (int r = sr; r >= 1; r--) {
        vector<int> next;
        for (int column : frontier) {
            for (int i : { -1, 0, 1 }) {
                int nr = r - 1;
                int nc = column + i;
                if (!(nr >= 0 and nr < n and nc >= 0 and nc < n))
                    continue;
                if (vis[nr][nc])
                    continue;
                if (g[nr][nc] == '.') {
                    next.push_back(nc);
                    vis[nr][nc] = true;
                } else if (g[nr][nc] == '#') {
                    int last = -1;
                    if (cfirst_wall[nc].size() > 0) last = cfirst_wall[nc].front();
                    if (nr == last) {
                        if (cfirst_wall[nc].size()) cfirst_wall[nc].pop();
                        next.push_back(nc);
                        vis[nr][nc] = true;
                    }
                }
            }
        }
        frontier = next;
    }
    for (bool x : vis[0])
        cout << x;
    cout << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        bop();
}