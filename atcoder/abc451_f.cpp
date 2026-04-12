#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

struct DSU {
    vector<int> parent, sz, parity;
    vector<array<int,2>> cnt; 
    DSU(int n) {
        parent.resize(n);
        parity.assign(n, 0);
        sz.assign(n, 1);
        cnt.assign(n, {1, 0});
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int,int> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto [p, par] = find(parent[x]);
        parity[x] ^= par;
        parent[x] = p;
        return {parent[x], parity[x]};
    }

    bool unite(int u, int v, int &ans) {
        auto [ru, pu] = find(u);
        auto [rv, pv] = find(v);
        if (ru == rv) {
            return (pu ^ pv) == 1;
        }
        if (sz[ru] > sz[rv]) {
            swap(ru, rv);
            swap(pu, pv);
        }
        ans -= min(cnt[ru][0], cnt[ru][1]);
        ans -= min(cnt[rv][0], cnt[rv][1]);
        int t = pu ^ pv ^ 1;
        parent[ru] = rv;
        parity[ru] = t;
        if (t == 0) {
            cnt[rv][0] += cnt[ru][0];
            cnt[rv][1] += cnt[ru][1];
        } else {
            cnt[rv][0] += cnt[ru][1];
            cnt[rv][1] += cnt[ru][0];
        }
        sz[rv] += sz[ru];
        ans += min(cnt[rv][0], cnt[rv][1]);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    DSU dsu(n);
    int ans = 0; 
    bool ok = true;
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; --u, --v;
        if (dsu.unite(u, v, ans) and ok) {
            cout << ans << '\n';
        } else {
            ok = false;
            cout << -1 << '\n';
        }
    }
}