#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct SegTree {
    int n;
    vector<bitset<26>> tree;
    SegTree(int _n) : n(_n) {
        tree.resize(4 * n);
    }
    void build(string& a, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = bitset<26>(0);
            tree[v] |= (1 << (a[l] - 'a'));
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
        }
    }

    void update(int pos, char val, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = bitset<26>(0);
            tree[v] |= (1 << (val - 'a'));
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2 + 1);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
        }
    }

    bitset<26> query(int a, int b, int l, int r, int v = 0) {
        if (b < l or a > r) return bitset<26>(0);
        if (a <= l and r <= b) return tree[v];
        int mid = (l + r) / 2;
        bitset<26> left = query(a, b, l, mid, v * 2 + 1);
        bitset<26> right = query(a, b, mid + 1, r, v * 2 + 2);
        return left | right;
    }
};
void dale() {
    string s;
    cin >> s;
    int n = s.size();
    SegTree tree(n);
    tree.build(s, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            char y; cin >> y;
            tree.update(--x, y, 0, n - 1);
        } else {
            int y; cin >> y;
            bitset<26> b = tree.query(--x, --y, 0, n - 1);
            cout << b.count() << '\n';
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}