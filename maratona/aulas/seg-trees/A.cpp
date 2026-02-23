#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
class SegTree {
    private:
    int n;
    vector<int> tree;
    void build(const vector<int> &a, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2 + 1);
            build(a, mid + 1, r, v * 2 + 2);
            tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    void update(int pos, int val, int l, int r, int v = 0) {
        if (l == r) {
            tree[v] = val;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2 + 1);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    int query(int a, int b, int l, int r, int v = 0) {
        if (b < l || a > r) return 0;
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        int left = query(a, b, l, mid, v * 2 + 1);
        int right = query(a, b, mid + 1, r, v * 2 + 2);
        return max(left, right);
    }
    public:
    SegTree(int n): n(n) {
        tree.assign(4 * n, 0);
    }
    void build(const vector<int> &a, int v = 0) {
        build(a, 0, n - 1, 0);
    }
    void update(int pos, int val, int v = 0) { 
        update(pos, val, 0, n - 1, 0);
    }
    int query(int a, int b, int v = 0) {
        return query(a, b, 0, n - 1, 0);
    }
};
void dale() {
    int n, m; cin >> n >> m;
    vector<int> h(n), r(m);
    for (int &i: h) cin >> i;
    for (int &i: r) cin >> i;
    SegTree tree(n);
    tree.build(h);
    for (int x: r) {
        int lo = -1, hi = n, found = false;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            int mx = tree.query(lo, mid);
            if (mx >= x) {
                found = true;
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if (found == false) {
            cout << 0 << ' ';
        } else {
            int val = tree.query(hi, hi);
            tree.update(hi, val - x);
            cout << hi + 1 << ' ';
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}