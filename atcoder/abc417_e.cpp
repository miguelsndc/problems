#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) (int((x).size()))
typedef pair<int, int> pii;
const int inf = 1e9;
void dale() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector g(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, false), pai(n + 1, -1);
    auto dfs = [&] (auto &&dfs, int u) -> void {
        vis[u] = true;
        sort(g[u].begin(), g[u].end());
        for (int v: g[u]) {
            if (!vis[v]) {
                pai[v] = u;
                dfs(dfs, v);
            }
        }
    };
    dfs(dfs, x);
    vector<int> path;
    for (int i = y; i != -1; i = pai[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < sz(path); i++) cout << path[i] << " \n"[i == sz(path) - 1];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}