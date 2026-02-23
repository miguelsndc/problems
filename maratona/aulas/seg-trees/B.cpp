#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
struct Node {
    ll max_sum = 0, sum = 0, mx_ps = 0, mx_ss = 0;
    Node(ll mxsum, ll sum, ll mxps, ll mxss) : max_sum(mxsum), sum(sum), mx_ps(mxps), mx_ss(mxss) {}
    Node() = default;
    static inline Node merge(Node& left, Node& right) {
        ll s =  left.sum + right.sum;
        ll mxps = max({left.sum + right.mx_ps, left.mx_ps, left.sum + right.sum, left.sum, 0ll });
        ll mx_ss = max({right.sum + left.mx_ss, right.mx_ss, right.sum + left.sum, right.sum, 0ll});
        ll next = max({mxps, left.max_sum, right.max_sum, mx_ss, left.mx_ss + right.mx_ps, 0ll});
        return Node(next, s, mxps, mx_ss);
    };
    void apply(int val) {
        sum = val;
        max_sum = max(val, 0);
        mx_ps = max_sum;
    }
};
struct SegTree {
    int n;
    vector<Node> tree;
    void build(const vector<int>& a, int l, int r, int v = 0) {
        if (l == r) {
            tree[v].apply(a[l]);
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = Node::merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    void update(int pos, int val, int l, int r, int v = 0) {
        if (l == r) {
            tree[v].apply(val);
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2 + 1);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = Node::merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    Node query(int a, int b, int l, int r, int v = 0) {
        if (b < l || a > r) return Node();
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        Node left = query(a, b, l, mid, v * 2 + 1);
        Node right = query(a, b, mid + 1, r, v * 2 + 2);
        return Node::merge(left, right);
    }

    SegTree(int n) : n(n) {
        tree.assign(4 * n, Node());
    }
    void build(const vector<int>& a, int v = 0) {
        build(a, 0, n - 1, 0);
    }
    void update(int pos, int val, int v = 0) {
        update(pos, val, 0, n - 1, 0);
    }
};
void dale() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int& i : x) cin >> i;
    SegTree tree(n);
    tree.build(x);
    while (m--) {
        int k, x;
        cin >> k >> x;
        --k;
        tree.update(k, x);
        cout << tree.tree[0].max_sum << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}