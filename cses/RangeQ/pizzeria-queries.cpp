#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
struct SegTree {
    int sz;
    vector<int> tree;
    SegTree(int n) : sz(n) {
        tree.resize(4 * n);
    };
    int merge(int &left, int &right) {
        return min(left, right);
    };
    void build(vector<int> &a, int l, int r, int v) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    void update(int pos, int val, int l, int r, int v) {
        if (l == r) {
            tree[v] = val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2 + 1);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    int query(int a, int b, int l, int r, int v) {
        if (b < l || a > r) return (int)(1e9 + 1);
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        int left = query(a, b, l, mid, v * 2 + 1);
        int right = query(a, b, mid + 1, r, v * 2 + 2);
        return merge(left, right);
    }
};
void dale() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = (a[i] - (i + 1));
        c[i] = (a[i] + (i + 1));
    }
    SegTree left(n), right(n);
    left.build(b, 0, n - 1, 0);
    right.build(c, 0, n - 1, 0);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            left.update(k - 1, x - k, 0, n - 1, 0);
            right.update(k - 1, x + k, 0, n - 1, 0);
        } else {
            int k;
            cin >> k;
            --k;
            int lo = left.query(0, k, 0, n - 1, 0) + (k + 1);
            int hi = right.query(k, n - 1, 0, n - 1, 0) - (k + 1);
            cout << min(lo, hi) << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}