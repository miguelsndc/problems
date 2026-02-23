#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 1005;
int mat[ms][ms], n, m, vis[ms][ms];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool pode(int r, int c) {
    return r >= 0 and c >= 0 and r < n and c < m and !vis[r][c] and mat[r][c] > 0;
}
ll bfs(int y, int x) {
    ll sum = 0;
    queue<ii> q;
    q.push({y, x});
    vis[y][x] = true;
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        sum += mat[r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (pode(nr, nc)) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return sum;
}
void dale() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] or mat[i][j] == 0) continue;
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}