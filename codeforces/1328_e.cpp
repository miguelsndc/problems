#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, m; cin >> n >> m;
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    int timer = 0;
    vector<int> depth(n), pai(n), tin(n), tout(n);
    auto ancestral = [&] (int u, int v) {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    };
    auto dfs = [&] (auto &dfs, int u, int p = -1, int d = 0) -> void {
        pai[u] = p;
        depth[u] = d;
        tin[u] = ++timer;
        for (int v: g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u, d + 1);
        }
        tout[u] = ++timer;
    };
    dfs(dfs, 0);
    while(m--) {
        int k; cin >> k;
        vector<int> q(k);
        for (int i = 0; i < k; i++) cin >> q[i], --q[i];
        for (int &u: q) if (pai[u] != -1) u = pai[u];
        sort(q.begin(), q.end(), [&] (int v1, int v2) {
            return depth[v1] > depth[v2];
        });
        bool ok = true;
        for (int i = 1; i < k; i++) {
            ok &= (ancestral(q[i], q[i - 1]));
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}