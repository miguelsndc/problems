#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
/*
    lca({a,b,c,d,e}) = lca(a, lca(b, lca(c, lca(d, e))))
    lca do conjunto ~ O(nlogn)
*/
const int mxn = 1005;
void dale() {
    int n, q; cin >> n >> q;
    vector tree(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }
    vector<bitset<mxn>> bs(n);
    vector<int> folha(n), depth(n);
    auto dfs = [&] (auto &dfs, int u, int p = -1, int d) -> void {
        bs[u].set(u, 1);
        depth[u] = d;
        folha[u] = true;
        for (int v: tree[u]) {
            if (v == p) continue;
            folha[u] = false;
            dfs(dfs, v, u, d + 1);
            bs[u] |= bs[v];
        }
    };
    dfs(dfs, 0, -1, 0);
    while(q--) {
        int k, m; cin >> k >> m;
        bitset<mxn> cur;
        for (int i = 0; i < m; i++) {
            int x; cin >> x; --x;   
            cur.set(x, 1);
        }
        vector<vector<int>> por_prof(n);
        for (int i = 0; i < n; i++) {
            if (folha[i]) continue;
            auto novo = cur & bs[i];
            if (novo.count() >= k) {
                por_prof[depth[i]].push_back(i);
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (por_prof[i].empty()) continue;
            ans = por_prof[i].size();
            break;
        }
        cout << ans << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}