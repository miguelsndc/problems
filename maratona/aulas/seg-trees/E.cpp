#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int ms = 2e5 + 10;
ll seg[4 * ms], lz[4 * ms], a[ms], inf = 1e18;
void build(int l, int r, int v = 0) {
    if (l == r) {
        seg[v] = a[l];
    }
    else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        seg[v] = min(seg[v * 2 + 1], seg[v * 2 + 2]);
    }
}
void push(int v) {
    seg[v * 2 + 1] += lz[v];
    seg[v * 2 + 2] += lz[v];
    lz[v * 2 + 1] += lz[v];
    lz[v * 2 + 2] += lz[v];
    lz[v] = 0;
}
void update(int a, int b, int l, int r, int add, int v = 0) {
    if (b < l or a > r) return;
    if (a <= l and r <= b) {
        seg[v] += add;
        lz[v] += add;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    update(a, b, l, m, add, v * 2 + 1);
    update(a, b, m + 1, r, add, v * 2 + 2);
    seg[v] = min(seg[v * 2 + 1], seg[v * 2 + 2]);
}
ll query(int a, int b, int l, int r, int v = 0) {
    if (b < l or a > r) return inf;
    if (a <= l and r <= b) {
        return seg[v];
    }
    push(v);
    int m = (l + r) / 2;
    ll left = query(a, b, l, m, v * 2 + 1);
    ll right = query(a, b, m + 1, r, v * 2 + 2);
    return min(left, right);
}
void dale() {
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) cin >> a[i];
    cin.ignore();
    build(0, n - 1);
    int m; cin >> m;
    cin.ignore();
    while(m--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<ll> qv; ll x;
        while(ss >> x) qv.push_back(x);
        ll l = qv[0], r = qv[1], add = inf;
        if (qv.size() == 3) {
            add = qv[2];
        }
        if (add == inf) {
            if (l <= r) {
                cout << query(l, r, 0, n - 1) << '\n';
            } else {
                ll first = query(0, r, 0, n - 1);
                ll second = query(l, n - 1, 0, n - 1);
                cout << min(first, second) << '\n';
            }
        } else {
             if (l <= r) {
                update(l, r, 0, n - 1, add);
            } else {
                update(0, r, 0, n - 1, add);
                update(l, n - 1, 0, n - 1, add);
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    dale();
}