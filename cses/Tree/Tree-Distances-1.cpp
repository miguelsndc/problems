#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 2e5 + 10;
int dist_l[mxn], dist_r[mxn], l, r, dist[mxn], n, inf = 1e9;
vector<int> g[mxn];
int mais_distante(int u) {
    fill(dist, dist + n + 1, inf);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    int mxd = 0, node = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] > mxd) {
            mxd = dist[u];
            node = u;
        }
        for (int v: g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return node;
}
void distancia(int u, int *dist) {
    fill(dist, dist + n + 1, inf);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    l = mais_distante(1);
    r = mais_distante(l);
    distancia(l, dist_l);
    distancia(r, dist_r);
    for (int i = 1; i <= n; i++) {
        cout << max(dist_l[i], dist_r[i]) << ' ';
    }
}