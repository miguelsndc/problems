#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10;
int n, m, dp[ms], ant[ms], in[ms], vis[ms];
vector<int> g[ms];
vector<int> order;
void dfs(int u) {
    vis[u] = true;
    for (int v: g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    order.push_back(u);
}
void dale() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(1);
    reverse(order.begin(), order.end());
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int u: order) {
        for (int v: g[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                ant[v] = u;
            }
        }
    }

    ant[1] = -1;
    vector<int> path;
    for (int i = n; i != -1; i = ant[i]) {
        path.push_back(i);
        if (i == 1) break;
    }
    cout << path.size() << '\n';
    for (int i = (int)(path.size() - 1); i >= 0; i--) {
        cout << path[i] << ' ';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}