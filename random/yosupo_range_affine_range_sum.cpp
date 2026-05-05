#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

const int ms = 5e5 + 5, mod = 998244353;
struct tag {
    ll b = 1, c = 0;
};
ll tree[4 * ms], a[ms]; tag lz[4 * ms];
void build(int l, int r, int v = 0) {
    if (l == r) {   
        tree[v] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, v * 2 + 1);
        build(mid + 1, r, v * 2 + 2);
        tree[v] = (tree[v * 2 + 1] + tree[v * 2 + 2]) % mod;
    }
}

void apply(int l, int r, int v, ll mul, ll add) {
    tree[v] = (tree[v] * mul % mod + (r - l + 1) * add % mod) % mod;
    lz[v].b = lz[v].b * mul % mod;
    lz[v].c = (lz[v].c * mul % mod + add) % mod;
}

void push(int l, int r, int v) {
    if (lz[v].b == 1 and lz[v].c == 0) return;
    int mid = (l + r) / 2;
    apply(l, mid, v * 2 + 1, lz[v].b, lz[v].c); 
    apply(mid + 1, r, v * 2 + 2, lz[v].b, lz[v].c); 
    lz[v] = {1, 0};
}

void update(int ql, int qr, int b, int c, int l, int r, int v = 0) {
    if (l > qr or r < ql) return;
    if (l >= ql and r <= qr) {
        apply(l, r, v, b, c);
        return;
    }
    push(l, r, v);
    int mid = (l + r) / 2;
    update(ql, qr, b, c, l, mid, v * 2 + 1);
    update(ql, qr, b, c, mid + 1, r, v * 2 + 2);
    tree[v] = (tree[v * 2 + 1] + tree[v * 2 + 2]) % mod;
}
ll query(int ql, int qr, int l, int r, int v = 0) {
    if (l > qr or r < ql) return 0;
    if (l >= ql and r <= qr) return tree[v];
    push(l, r, v);
    int mid = (l + r) / 2;
    ll left = query(ql, qr, l, mid, v * 2 + 1); 
    ll right = query(ql, qr, mid + 1, r, v * 2 + 2);
    return (left + right) % mod;
}
void slve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, n - 1);
    while (q--) {
        int t, l, r, b, c; cin >> t;
        if (t == 0) {
            cin >> l >> r >> b >> c;
            update(l, r - 1, b, c, 0, n - 1);
        } else {
            cin >> l >> r;
            cout << query(l, r - 1, 0, n - 1) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; //cin >> tt;
    while(tt--) slve();
}