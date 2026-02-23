#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct node {
    pii m, m2;
};
node merge(node &a, node &b) {
    node res;
    map<int,int> occ;
    occ[a.m.first] += a.m.second;
    occ[a.m2.first] += a.m2.second;
    occ[b.m.first] += b.m.second;
    occ[b.m2.first] += b.m2.second;
    vector<int> v = {a.m.first, b.m.first, a.m2.first, b.m2.first};
    sort(v.rbegin(), v.rend());
    v.erase(unique(v.begin(), v.end()), v.end());
    res.m = {v.front(), occ[v.front()]};
    res.m2 = {v[1], occ[v[1]]};
    return res;
};
struct SegTree {
    int n;
    vector<node> tree;
    SegTree(int _n) : n(_n) {
        tree.resize(4 * n);
    }
    void build(vector<int> &a, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = {{a[l], 1}, {-1, 0}};
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }

    void update(int pos, int val, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = {{val, 1}, {-1, 0}};
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2 + 1);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }

    node query(int a, int b, int l, int r, int v = 0) {
        if (b < l or a > r) return {{INT_MIN, 0}, {-1, 0}};
        if (a <= l and r <= b) return tree[v];
        int mid = (l + r) / 2;
        node left = query(a, b, l, mid, v * 2 + 1);
        node right = query(a, b, mid + 1, r, v * 2 + 2);
        return merge(left, right);
    }
};

void dale() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree tree(n);
    tree.build(a, 0, n - 1);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            tree.update(x, y, 0, n - 1);
        } else {
            --y;
            node ans = tree.query(x, y, 0, n - 1);
            cout << ans.m2.second << '\n';
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}
