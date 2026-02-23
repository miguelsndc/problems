#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
void dale() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    ll min_edge = INF;
    for (int i = 0; i < m; i++) {
        int u, v, w;        
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        min_edge = min(min_edge, (ll)w);
    }
    vector<ll> dist(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    vector<bool> fila(n + 1, true);
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        fila[u] = false;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!fila[v]) {
                    q.push(v);
                    fila[v] = true;
                    if (++cnt[v] > n) {
                        cout << "-inf\n";
                        return;
                    }
                }
            }
        }
    }
    ll ans = min_edge;
    for (int i = 1; i <= n; i++) ans = min(ans, dist[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) dale();
    return 0;
}