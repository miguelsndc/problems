#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int dist[maxn], mx1, d1, mx2, d2, n;
vector<int> g[maxn];
void mais_distante(int u, int p, int dep, int &mx, int &node) {
    dist[u] = dep;
    if (dep > mx) {
        mx = dep;
        node = u;
    }
    for (int v: g[u]) {
        if (v != p) mais_distante(v, u, dep + 1, mx, node);
    }
}
int distancia(int a, int b) {
    fill(dist, dist + n + 1, (int)1e9);
    dist[a] = 0;
    queue<int> q;
    q.push(a);
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
    return dist[b];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mais_distante(1, 0, 0, mx1, d1);
    mais_distante(d1, 0, 0, mx2, d2);
    cout << distancia(d1, d2) << '\n';
}