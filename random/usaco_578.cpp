#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
const int ms = 2e5 + 10;
struct node {
    ll min = 1e18, sum = 0;
};
node merge(const node&a, const node&b) {
    node res;
    res.min = min(a.min, b.min);
    res.sum = a.sum + b.sum;
    return res;
}
node tree[4 * ms]; ll lazy[4 * ms], a[ms];
void build(int l, int r, int v = 0) {
    if (l == r) {
        tree[v].min = tree[v].sum = a[l];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, v * 2 + 1);
        build(mid + 1, r, v * 2 + 2);
        tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
void apply(int l, int r, ll c, int v) {
    tree[v].sum += (r - l + 1) * c, tree[v].min += c;
    lazy[v] += c;
}
void push(int l, int r, int v) {
    if(lazy[v] == 0) return;
    int mid = (l + r) / 2;
    apply(l, mid, lazy[v], v * 2 + 1);
    apply(mid + 1, r, lazy[v], v * 2 + 2);
    lazy[v] = 0;
}
void update(int ql, int qr, int c, int l, int r, int v = 0) {
    if (l > qr or r < ql) return;
    if (l >= ql and r <= qr) {
        apply(l, r, c, v);
        return;
    }
    push(l, r, v);
    int mid = (l + r) / 2;
    update(ql, qr, c, l, mid, v * 2 + 1);
    update(ql, qr, c, mid + 1, r, v * 2 + 2);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}
node query(int ql, int qr, int l, int r, int v = 0) {
    if (l > qr or r < ql) return {(ll)1e18, 0};
    if (l >= ql and r <= qr) return tree[v];
    push(l, r, v);
    int mid = (l + r) / 2;
    node left = query(ql, qr, l, mid, v * 2 + 1);
    node right = query(ql, qr, mid + 1, r, v * 2 + 2);
    return merge(left, right);
}
void slve() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1);
    while(q--) {
        char t; int l, r, c;
        cin >> t; cin >> l >> r;
        if (t == 'M') {
            cout << query(--l, --r, 0, n - 1).min << '\n';
        }
        if (t == 'S') {
            cout << query(--l, --r, 0, n - 1).sum << '\n';
        }
        if (t == 'P') {
            cin >> c;
            update(--l, --r, c, 0, n - 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; //cin >> tt;
    while(tt--) slve();
}