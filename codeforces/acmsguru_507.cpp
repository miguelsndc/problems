#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;
const int ms = 5e4 + 5;
vector<int> g[ms]; ll folha[ms], ans[ms], val[ms];
ordered_set* dfs(int u, int p = -1) {
    folha[u] = true;
    auto s = new ordered_set();
    for (int v: g[u]) {
        if (v == p) continue;
        folha[u] = false;
        auto child = dfs(v, u);
        if (s->size() < child->size()) swap(s, child);
        for (auto& x: *child) s->insert(x);
        delete child;
    }
    // s tem todas as folhas da subarvore
    if(folha[u]) (*s).insert(val[u]);
    else {
        int x = s->size(); // 0 1 2 3 4 5 6
        if (x <= 1) {
            ans[u] = (1ll << 31) - 1;
        } else if (x % 2 == 0) {
            auto low = s->find_by_order(x/2 - 1);
            auto high = s->find_by_order(x/2);
            ans[u] = (*high - *low);
        } else {
            auto low = s->find_by_order(x/2 - 1);
            auto mid = s->find_by_order(x/2);
            auto high = s->find_by_order(x/2 + 1);
            ans[u] = min(*high - *mid, *mid - *low);
        }
    }
    return s;
}
void slve() {
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for (int j = n - m + 1; j <= n; j++) {
        cin >> val[j];
    }
    auto x = dfs(1);
    delete x;
    for (int i = 1; i <= n; i++) {
        if (!folha[i]) {
            cout << ans[i] << ' ';
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) slve();
}