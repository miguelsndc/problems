#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n;
    cin >> n;
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<int> depth(n), par(n), grau(n);
    auto dfs = [&](auto&& self, int u, int p = -1) -> void {
        if (p != -1) depth[u] = depth[p] + 1;
        par[u] = p;
        for (int x : g[u]) {
            if (x == p) continue;
            self(self, x, u);
            grau[u]++;
        }
    };
    dfs(dfs, n - 1);
    array<vector<int>, 2> folhas;
    folhas[0];
    for (int i = 0; i < n; i++) {
        if (grau[i] == 0) folhas[depth[i] & 1].push_back(i);
    }
    int col = depth[0] & 1;
    vector<array<int, 2>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (folhas[col ^ 1].empty()) {
            ans.push_back({1, -1});
            col ^= 1;
        }
        int next = folhas[col ^ 1].back();
        folhas[col ^ 1].pop_back();
        ans.push_back({2, next});
        int p = par[next];
        if (--grau[p] == 0) {
            folhas[depth[p] & 1].push_back(p);
        }
        ans.push_back({1, -1});
        col ^= 1;
    }
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        if (x == 1)
            cout << "1\n";
        else
            cout << "2 " << y + 1 << "\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}