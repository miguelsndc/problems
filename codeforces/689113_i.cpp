#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
int X;
struct Node {
    ll ans;
    int total_gcd, prefsz, sufsz;
    pii pre[23], suf[23];
};

Node faz(int val) {
    Node res;
    res.total_gcd = val;
    res.ans = (int)(val == X);
    res.prefsz = 1;
    res.pre[0] = {val, 1};
    res.sufsz = 1;
    res.suf[0] = {val, 1};
    return res;
}

Node merge (const Node &l, const Node &r) {
    if (l.prefsz == 0) return r;
    if (r.prefsz == 0) return l;
    Node res;
    res.ans = l.ans + r.ans;
    for (int i = 0; i < l.sufsz; i++) {
        for (int j = 0; j < r.prefsz; j++) {
            if (gcd(l.suf[i].first, r.pre[j].first) == X) {
                res.ans += 1ll * l.suf[i].second * r.pre[j].second;
            }
        }
    }
    res.total_gcd = gcd(l.total_gcd, r.total_gcd);
    res.prefsz = l.prefsz;
    for (int i = 0; i < l.prefsz; i++) res.pre[i] = l.pre[i];
    for (int j = 0; j < r.prefsz; j++) {
        int g = gcd(l.total_gcd, r.pre[j].first);
        if (res.pre[res.prefsz - 1].first == g) {
            res.pre[res.prefsz - 1].second += r.pre[j].second;
        } else {
            res.pre[res.prefsz++] = {g, r.pre[j].second};
        }
    }
    res.sufsz = r.sufsz;
    for (int i = 0; i < r.sufsz; i++) res.suf[i] = r.suf[i];
    for (int j = 0; j < l.sufsz; j++) {
        int g = gcd(r.total_gcd, l.suf[j].first);
        if (res.suf[res.sufsz - 1].first == g) {
            res.suf[res.sufsz - 1].second += l.suf[j].second;
        } else {
            res.suf[res.sufsz++] = {g, l.suf[j].second};
        }
    }
    return res;
}
const int ms = 1e5 + 5;
Node tree[4 * ms];
int a[ms];
void build(int l, int r, int v = 0) {
    if (l == r) {
        tree[v] = faz(a[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        tree[v] = merge(tree[v*2+1], tree[v*2+2]);
    }
}

Node query(int ql, int qr, int l, int r, int v = 0) {
    if (qr < l or ql > r) {
        Node vazio;
        vazio.prefsz = vazio.sufsz = 0;
        return vazio;
    }
    if (l >= ql and r <= qr) {
        return tree[v];
    }
    int m = (l + r) / 2;
    Node left = query(ql, qr, l, m, v * 2 + 1);
    Node right = query(ql, qr, m + 1, r, v * 2 + 2);
    return merge(left, right);
}

void update(int pos, int val, int l, int r, int v = 0) {
    if (l == r) {
        tree[v] = faz(val);
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(pos, val, l, m, v * 2 + 1);
        } else {
            update(pos, val, m + 1, r, v * 2 + 2);
        }
        tree[v] = merge(tree[v *2+1],tree[v*2+2]);
    }
}

void slve() {   
    int n, q; cin >> n >> q>> X;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1);
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, y; cin >> i >> y;
            update(--i, y, 0, n - 1);
        } else {
            int l, r; cin >> l >> r;
            auto vv = query(l - 1, r- 1, 0, n - 1);
            cout << vv.ans << '\n';
        }
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) slve();
}