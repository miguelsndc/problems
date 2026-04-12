#include <bits/stdc++.h>
using namespace std;

void dale() {
    int n, l, r;
    cin >> n >> l >> r;
    vector tree(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }
    vector<int> sz(n), big(n, -1), depth(n);
    long long total = 0;
    struct BIT {
        int n;
        vector<long long> bit;
        BIT(int _n = 0) { init(_n); }
        void init(int _n) {
            n = _n;
            bit.assign(n + 1, 0);
        }
        // add val at position pos (0-based)
        void add(int pos, int val = 1) {
            for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
        }
        // sum [0..pos] (0-based)
        long long sum(int pos) const {
            if (pos < 0) return 0;
            long long s = 0;
            for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
            return s;
        }
    };

    BIT bit(n + 1);

    auto dfs_sz = [&](auto&& self, int u, int p, int d) -> void {
        sz[u] = 1;
        int max_sub = 0;
        depth[u] = d;
        for (int v : tree[u]) {
            if (v == p) continue;
            self(self, v, u, d + 1);
            sz[u] += sz[v];
            if (sz[v] > max_sub) {
                max_sub = sz[v];
                big[u] = v;
            }
        }
    };
    auto query_node = [&](auto&& self, int curr, int p, int base,
                          int x) -> void {
        int max_depth = x + 2 * depth[base] - depth[curr];
        if (max_depth >= 0) {
            total += bit.sum(min(n, max_depth));
        }
        for (int v : tree[curr]) {
            if (v == p) continue;
            self(self, v, curr, base, x);
        }
    };
    auto update_node = [&](auto&& self, int u, int p, int delta) -> void {
        bit.add(depth[u], delta);
        for (int v : tree[u]) {
            if (v == p) continue;
            self(self, v, u, delta);
        }
    };

    auto dfs = [&](auto&& self, int u, int p, bool keep, int x) -> void {
        for (int v : tree[u]) {
            if (v == p or big[u] == v) continue;
            self(self, v, u, false, x);
        }

        if (big[u] != -1) {
            self(self, big[u], u, true, x);
        }

        for (int v : tree[u]) {
            if (v == p or v == big[u]) continue;
            query_node(query_node, v, u, u, x);
            update_node(update_node, v, u, 1);
        }
        int max_depth = x + depth[u];
        if (max_depth >= 0) {
            total += bit.sum(min(n, max_depth));
        }
        bit.add(depth[u], 1);
        if (!keep) {
            update_node(update_node, u, p, -1);
        }
    };

    auto solve = [&](int x) -> long long {
        if (x < 0) return 0;
        total = 0;
        bit.init(n + 1);
        dfs(dfs, 0, -1, true, x);
        return total;
    };
    dfs_sz(dfs_sz, 0, -1, 0);
    long long ans = solve(n - 1 - l) - solve(n - 1 - r - 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) dale();
}
