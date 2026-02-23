#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node {
    ll cnt = 0;
    vector<ll> freq, pre;
    Node() {
        freq.assign(41, 0);
        pre.assign(41, 0);
    }
    void set(int pos) {
        freq[pos]++;
        for (int i = 1; i <= 40; i++) pre[i] = pre[i - 1] + freq[i]; 
    }
};
Node merge(Node &a, Node &b) {
    Node res;
    for (int i = 0; i <= 40; i++) res.freq[i] = a.freq[i] + b.freq[i];
    for (int i = 1; i <= 40; i++) res.pre[i] = res.pre[i - 1] + res.freq[i]; 
    res.cnt = a.cnt + b.cnt;
    for (int i = 1; i <= 40; i++) res.cnt += 1ll* a.freq[i] * b.pre[i - 1];
    return res;
};
struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(int _n) : n(_n) {
        tree.assign(4 * n, Node());
    }
    void build(vector<int>& a, int l, int r, int v = 0) {
        if (l == r) {
            tree[v].set(a[l]);
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }

    void update(int pos, int val, int l, int r, int v = 0) {
        if (l == r) {
            fill(tree[v].freq.begin(), tree[v].freq.end(), 0);
            fill(tree[v].pre.begin(), tree[v].pre.end(), 0);
            tree[v].set(val);
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

    Node query(int a, int b, int l, int r, int v = 0) {
        if (b < l or a > r) return Node();
        if (a <= l and r <= b) return tree[v];
        int mid = (l + r) / 2;
        Node left = query(a, b, l, mid, v * 2 + 1);
        Node right = query(a, b, mid + 1, r, v * 2 + 2);
        return merge(left, right);
    }
};

void dale() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    SegTree tree(n);
    tree.build(a, 0, n - 1);
    while(q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            --x, --y;
            cout << tree.query(x, y, 0, n - 1).cnt << "\n";
        } else {
            --x;
            tree.update(x, y, 0, n - 1);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}