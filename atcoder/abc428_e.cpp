#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> distancia(n), dist_left(n), dist_right(n);
    auto distantes = [&](auto && dfs, int u, vector<int>&dist, int p = -1) -> void {
        for (int v: g[u]) {
            if (v != p) {
                dist[v] = dist[u] + 1;
                dfs(dfs, v, dist, u);
            }
        }
    };
    int diam_esq = -1, mxd = -1, diam_dir = -1;
    distantes(distantes, 0, distancia, -1);
    for (int i = 0; i < n; i++) {
        if (distancia[i] >= mxd) {
            mxd = distancia[i];
            diam_esq = i;
        }
    }
    mxd = -1;
    distantes(distantes, diam_esq, dist_left, -1);
    for (int i = 0; i < n; i++) {
        if (dist_left[i] >= mxd) {
            mxd = dist_left[i];
            diam_dir = i;
        }
    }
    distantes(distantes, diam_dir, dist_right, -1);
    for (int i = 0; i < n; i++) {
        if (dist_left[i] > dist_right[i]) {
            cout << diam_esq + 1 << '\n';
        } else if (dist_left[i] < dist_right[i]) {
            cout << diam_dir + 1 << '\n';
        } else {
            cout << max(diam_esq, diam_dir) + 1 << '\n';
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}