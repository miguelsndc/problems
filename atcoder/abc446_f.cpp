#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 3e5 + 10;
int can[ms], vis[ms], cnt_vis = 0, cnt_can = 0;
vector<int> g[ms];
void dfs(int i, int mx) {
    vis[i] = true;
    cnt_vis++;
    for (int v : g[i]) {
        if (!vis[v] and v <= mx) dfs(v, mx);
        if (!can[v]) {
            can[v] = true;
            cnt_can++;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            can[i] = true;
            cnt_can++;
        }
        if (can[i]) dfs(i, i);
        if (cnt_vis == i)
            cout << (cnt_can - cnt_vis) << '\n';
        else
            cout << -1 << '\n';
    }
}
