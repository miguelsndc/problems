#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
const int ms = 1e5 + 10, LOG = 20;
struct query {
    int b, c, id;
};
vector<int> g[ms], t[ms];
int val[ms], ans[ms], up[LOG][ms], depth[ms], tin[ms], tout[ms], timer = 0; 
vector<query> queries[ms];


void dfs2(int u, int p = 1) {
    tin[u] = ++timer;
    depth[u] = depth[p] + 1;
    up[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v: g[u]) {
        if (v != p) dfs2(v, u);
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v)  {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int a, int b) {
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i = LOG - 1; i >= 0; i--) {
        if (!is_ancestor(up[i][a], b)) {
            a = up[i][a];
        }
    }
    return up[0][a];
}

void dfs(int u, int p = -1) {
    t[val[u]].push_back(depth[u]);
    for (auto &[v, c, id]: queries[u]) {
        int pai = lca(u, v);
        if (t[c].size() and t[c].back() >= depth[pai]) {
            ans[id] = true;
        }
    }
    for (int v: g[u]) {
        if (v != p) dfs(v, u);
    }
    t[val[u]].pop_back();
}

void slve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        queries[a].push_back({b, c, i});
        queries[b].push_back({a, c, i});
    }
    dfs2(1);
    dfs(1);
    for (int i = 0; i < m; i++) {
        cout << ans[i];
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) slve();
}