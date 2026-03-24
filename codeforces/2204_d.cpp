#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    vector<int> color(n, -1);
    vector<int> comp(2, 0);
    auto check_bipartite = [&](auto&& self, int u, int cor) -> int {
        color[u] = cor;
        comp[cor]++;
        for (int v : g[u]) {
            if (color[v] == -1) {
                if (!self(self, v, cor ^ 1)) return false;
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    };
    auto ajeita = [&](auto&& self, int u) -> void {
        color[u] = 2;
        for (int v : g[u]) {
            if (color[v] != 2) {
                self(self, v);
            }
        }
    };
    int ans = 0;
    for (int v = 0; v < n; v++) {
        comp[0] = comp[1] = 0;
        if (color[v] != -1) continue;
        if (check_bipartite(check_bipartite, v, 0)) {
            ans += max(comp[0], comp[1]);
        } else {
            ajeita(ajeita, v);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
