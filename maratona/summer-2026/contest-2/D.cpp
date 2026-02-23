#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
struct SegmentTree {
private:
    vector<int> tree;
    const int NEUTRAL = 0;

public:
    SegmentTree(int _n) {
        tree.resize(8 * _n);
    }

    int join(int a, int b) { return max(a, b); }

    void point_update(int pos, int val, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                point_update(pos, val, l, mid, v * 2 + 1);
            } else {
                point_update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }

    void range_set(int a, int b, int val, int l, int r, int v = 0) {
        if (b < l || a > r) return;
        if (a <= l && r <= b) {
            tree[v] = max(tree[v], val);
            return;
        }
        int mid = l + (r - l) / 2;
        range_set(a, b, val, l, mid, v * 2 + 1);
        range_set(a, b, val, mid + 1, r, v * 2 + 2);
    }

    int point_query(int pt, int l, int r, int v = 0) {
        int current = tree[v];
        if (l == r) {
            return current;
        } 
        int mid = (l + r) / 2;
        if (pt <= mid) {
            return max(current, point_query(pt, l, mid, v * 2 + 1));
        } else {
            return max(current, point_query(pt, mid + 1, r, v * 2 + 2));
        }
    }

    int range_query(int a, int b, int l, int r, int v = 0) {
        if (b < l || a > r) return NEUTRAL;
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        int left = range_query(a, b, l, mid, v * 2 + 1);
        int right = range_query(a, b, mid + 1, r, v * 2 + 2);
        return join(left, right);
    }
};
void dale() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<int> tin(n), tout(n);
    int timer = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto dfs = [&](auto& dfs, int u, int p = -1) -> void {
        tin[u] = timer++;
        for (int v : tree[u])
            if (v != p) {
                dfs(dfs, v, u);
            }
        tout[u] = timer;
    };
    dfs(dfs, 0);
    int q;
    cin >> q;
    SegmentTree seg_fill(timer + 1), seg_empty(timer + 1);
    int t = 1;
    while(q--) {
        int c, v;
        cin >> c >> v;
        --v;
        if (c == 1) {
            seg_fill.range_set(tin[v], tout[v] - 1, t, 0, timer);
            t++;
        } else if (c == 2) {
            seg_empty.point_update(tin[v], t, 0, timer);
            t++;
        } else {
            int v1 = seg_fill.point_query(tin[v], 0, timer); 
            int v2 = seg_empty.range_query(tin[v], tout[v] - 1, 0, timer);
            if (v1 > v2) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}