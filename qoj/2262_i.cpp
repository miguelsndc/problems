#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = 1LL << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    return ans + ((seg == 1 || seg == 2) ? add : (subSquareSize - add - 1));
}


struct segment_tree {
    int n;
    vector<pii> tree; 
    pii merge(pii x, pii y) {
        return max(x, y);
    }
    segment_tree(int n) : n(n), tree(2 * n, {-1, -1}) {}
    void update(int i, pii x) {
        tree[i += n] = x;
        while (i >>= 1) tree[i] = merge(tree[i << 1], tree[(i << 1) | 1]);
    }
    pii query(int i, int j) {
        if (i > j) return {-1, -1};
        pii l = {-1, -1}, r = {-1, -1};
        for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) l = merge(l, tree[i++]);
            if (j & 1) r = merge(tree[--j], r);
        }
        return merge(l, r);
    }
};

const int BLOCK = 200;

struct Query {
    int v, l, r, id;
    int64_t ord = hilbertOrder(l, r, 21, 0);  // use se hilbert
    bool operator<(const Query& o) const {
        return ord < o.ord;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector tree(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        --p;
        tree[p].push_back(i + 1);
        tree[i + 1].push_back(p);
    }
    
    int timer = -1;
    vector<int> tin(n), tout(n), et(n), depth(n);
    vector<vector<int>> up(n, vector<int>(15));

    auto euler = [&](auto&& self, int u, int p) -> void {
        tin[u] = ++timer;
        et[timer] = u;
        up[u][0] = (p == -1 ? u : p);
        for (int i = 1; i < 15; i++) {
            up[u][i] = up[up[u][i-1]][i-1];
        }

        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
        }
        tout[u] = timer;
    };
    
    euler(euler, 0, -1);
    
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].v >> queries[i].l >> queries[i].r;
        --queries[i].v; --queries[i].l; --queries[i].r;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end()); 
    
    vector<int> ans(q);
    segment_tree seg(n);
    
    auto add = [&] (int i) {
        seg.update(tin[i], {depth[i], i});
    };
    auto remove = [&] (int i) {
        seg.update(tin[i], {-1, -1});
    };
    
    int L = 0, R = -1;
    for (auto &q: queries) {
        while (L > q.l) add(--L);
        while (R < q.r) add(++R);
        while (L < q.l) remove(L++);
        while (R > q.r) remove(R--);
        
        int v = q.v;
        pii best = seg.query(tin[v], tout[v]);
        if (best.first == -1 || best.second == v) {
            ans[q.id] = -1;
            continue;
        }
        
        int u1 = best.second;
        int c = u1;
        for (int k = 14; k >= 0; k--) {
            if (depth[c] - (1 << k) > depth[v]) {
                c = up[c][k];
            }
        }
        pii left_max = seg.query(tin[v], tin[c] - 1);
        pii right_max = seg.query(tout[c] + 1, tout[v]);
        int mx2 = max(left_max.first, right_max.first);
        if (mx2 == -1) {
            ans[q.id] = -1; 
        } else {
            ans[q.id] = (best.first - depth[v]) + (mx2 - depth[v]);
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
}