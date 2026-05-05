#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
const int ms = 1e5 + 5, mod = 1e9 + 7;
ll tree[4 * ms], lz[4 * ms], squared[4 * ms], a[ms];
void build(int l, int r, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
        squared[v] = (a[l] * a[l]) % mod;
    }
    else {
        int mid = (l + r) / 2;
        build(l, mid, v * 2 + 1);
        build(mid + 1, r, v * 2 + 2);
        tree[v] = (tree[v * 2 + 1] + tree[v * 2 + 2]) % mod;
        squared[v] = (squared[v * 2 + 1] + squared[v * 2 + 2]) % mod;
    }
}
void apply(int l, int r, int v) {
    if (lz[v] == 0) return;
    if (l != r) {
        (lz[2 * v + 1] += lz[v] + mod) %= mod;
        (lz[2 * v + 2] += lz[v] + mod) %= mod;
    }
    (squared[v] += (2 * lz[v] % mod * tree[v] % mod + (r - l + 1) * lz[v] % mod * lz[v] % mod) % mod + mod) %= mod;
    (tree[v] += ((r - l + 1) * lz[v] % mod) % mod + mod) %= mod;
    lz[v] = 0;
}
void update(int ql, int qr, ll x, int l, int r, int v = 0) {
    apply(l, r, v);
    if (l > qr or r < ql) return;
    if (ql <= l and r <= qr) {
        (lz[v] += x + mod) %= mod;
        apply(l, r, v);
        return;
    }
    int mid = (l + r) / 2;
    update(ql, qr, x, l, mid, v * 2 + 1);
    update(ql, qr, x, mid + 1, r, v * 2 + 2);
    tree[v] = (tree[v * 2 + 1] + tree[v * 2 + 2]) % mod;
    squared[v] = (squared[v * 2 + 1] + squared[v * 2 + 2]) % mod;
}
ll query(int ql, int qr, int l, int r, int v = 0) {
    apply(l, r, v);
    if (l > qr || r < ql) return 0; // valor neutro
    if (ql <= l && r <= qr) return squared[v];
    int mid = (l + r) / 2;
    return (query(ql, qr, l, mid, 2 * v + 1) + query(ql, qr, mid + 1, r, 2 * v + 2)) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1);
    while (q--) {
        char t; int l, r, x;
        cin >> t;
        if (t == 'u') {
            cin >> l >> r >> x; --l, --r;
            update(l, r, x, 0, n - 1);
        }
        else {
            cin >> l >> r;
            cout << query(--l, --r, 0, n - 1) << '\n';
        }
    }
}