#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 1e9 + 1;
void dale() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v;
        cin >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    vector<int> dist(n + 1, inf);
    vector<int> prev(n + 1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, _] : g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    set<int> frontier{1};
    string s;
    prev[1] = -1;
    for (int i = 0; i < dist[1]; i++) {
        char best = 'z';
        vector<int> caras;
        for (int node : frontier) {
            for (auto [v, c] : g[node]) {
                if (dist[v] == dist[node] - 1 and c < best) {
                    best = c;
                }
            }
        }
        s += best;
        set<int> bons;
        for (int node : frontier) {
            for (auto [v, c] : g[node]) {
                if (dist[v] == dist[node] - 1 and c == best) {
                    bons.insert(v);
                    prev[v] = node;
                }
            }
        }
        swap(frontier, bons);
    }
    vector<int> path;
    for (int i = n; i != -1; i = prev[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    cout << s.size() << '\n';
    for (int x : path) cout << x << ' ';
    cout << '\n';
    cout << s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}
