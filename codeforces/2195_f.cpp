#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dag(n); vector<int> in(n), dp_in(n, 1), dp_out(n, 1);
    auto intersecta = [&](int i, int j) {
        bool ok = false;
        if (a[i] == a[j]) {
            return b[i] != b[j];
        }
        else {
            ll delta = (b[i] - b[j]) * (b[i] - b[j]) - 4 * (a[i] - a[j]) * (c[i] - c[j]);
            ok = delta >= 0;
        }
        return ok;
        };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intersecta(i, j)) continue;
            if (a[i] > a[j]) dag[j].push_back(i), in[i]++;
            else if (a[i] == a[j]) {
                if (c[i] > c[j]) {
                    dag[j].push_back(i), in[i]++;
                }
                else {
                    dag[i].push_back(j), in[j]++;
                }
            }
            else {
                dag[i].push_back(j), in[j]++;
            }

        }
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : dag[u]) {
            if (--in[v] == 0) q.push(v);
            dp_in[v] = max(dp_in[v], dp_in[u] + 1);
        }
    }

    for (int u = n - 1; u >= 0; u--) {
        for (int v : dag[topo[u]]) {
            dp_out[topo[u]] = max(dp_out[topo[u]], dp_out[v] + 1);
        }
    }

    for (int i = 0; i < n; i++) cout << dp_in[i] + dp_out[i] - 1 << " \n"[i == n - 1];
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}