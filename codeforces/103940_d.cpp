#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector g(n, vector<pii>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[--a].push_back({--b, c});
        g[b].push_back({a, c});
    }
    const int inf = 1e9;
    vector<int> dist(n, inf), vis(n, false);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& [v, w] : g[u]) {
            if (vis[v]) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
            vis[v] = true;
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int minc = 1e6;
        for (auto &[v, c]: g[i]) {
            if (dist[v] == dist[i] - 1) {
                minc = min(minc, c);
            }
        }
        ans += 1ll * dist[i] * minc;
    }
    cout << ans << '\n';
}
