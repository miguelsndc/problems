#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
const ll neginf = -1e18;
struct Node {
    ll sum = 0, mx_pref = 0;
    Node(): sum(0), mx_pref(0) {} 
    Node(ll _s, ll _m): sum(_s), mx_pref(_m) {}
};
struct SegTree {
    int sz; 
    vector<Node> tree;
    SegTree(int n): sz(n) {
        tree.resize(4 * n);
    };
    Node merge(Node &left, Node&right) {
        ll sum = left.sum + right.sum;
        ll mx_pref = max(left.mx_pref, left.sum + right.mx_pref);
        return Node(sum, mx_pref);
    };
    void build(vector<int> &a, int l, int r, int v) {
        if (l == r) {
            tree[v] = {a[l], a[l]};
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    void update(int pos, int val, int l, int r, int v) {
        if (l == r) {
            tree[v] = {val, val};
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
    Node query(int a, int b, int l, int r, int v) {
        if (b < l || a > r) return {0, 0};
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        Node left = query(a, b, l, mid, v * 2 + 1);
        Node right = query(a, b, mid + 1, r, v * 2 + 2);
        return merge(left, right);
    }
};
void dale() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(n);
    seg.build(a, 0, n - 1, 0);
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            seg.update(--k, u, 0, n- 1, 0);
        } else {
            int a, b; cin >> a >> b; --a,--b;
            cout << max(seg.query(a, b, 0, n - 1, 0).mx_pref, 0ll)<< '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}