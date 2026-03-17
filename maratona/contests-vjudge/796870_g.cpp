#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
int n, m, k, s, t;
const int ms = 1e3 + 5;
vector<int> pts, vis(ms);
vector<array<int, 3>> g[ms];
bool dfs(int u, int rep) {
    vis[u] = true;
    bool alcança = false;
    for (auto [v, c, d] : g[u]) {
        if (!(c <= rep and rep <= d) or vis[v]) continue;
        if (v == t) {
            return true;
        } else {
            alcança |= dfs(v, rep);
        }
    }
    return alcança;
}
void solve() {
    cin >> n >> m >> k >> s >> t;
    pts.push_back(1);
    pts.push_back(k + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        pts.push_back(c);
        pts.push_back(d + 1);
    }
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    i64 ans = 0;
    for (int i = 0; i + 1 < (int)(pts.size()); i++) {
        int rep = pts[i];
        vis.assign(ms, 0);
        if (dfs(s, rep)) {
            ans += pts[i + 1] - pts[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
