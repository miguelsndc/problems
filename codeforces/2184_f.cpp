#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }
    auto dfs = [&](auto&& dfs, int u, int par) -> vector<int> {
        vector<int> cur = {1, 0, 0};
        bool folha = true;
        for (int v : tree[u]) {
            if (v == par) continue;
            folha = false;
            vector<int> next ={0, 0, 0};
            auto filho = dfs(dfs, v, u);
            for (int i = 0; i < 3; i++) {
                if (cur[i]) {
                    for (int j = 0; j < 3; j++) {
                        if (filho[j]) next[(i + j) % 3] = 1;
                    }
                }
            }
            cur = next;
        }
        if (folha) {
            return {0, 1, 0};
        }
        cur[1] = 1;
        return cur;
    };
    auto dp = dfs(dfs, 0, -1);
    if (dp[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}