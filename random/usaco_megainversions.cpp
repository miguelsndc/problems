#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int maxv = n;
    vector<ll> tree_left(4 * (maxv + 5)), tree_right(4 * (maxv + 5));

    auto query = [&](auto &&self, vector<ll> &tree, int ql, int qr, int l, int r, int v) -> ll {
        if (ql > qr) return 0;
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[v];
        int mid = (l + r) / 2;
        return self(self, tree, ql, qr, l, mid, v * 2 + 1)
             + self(self, tree, ql, qr, mid + 1, r, v * 2 + 2);
    };

    auto update = [&](auto &&self, vector<ll> &tree, int pos, int val, int l, int r, int v) -> void {
        if (l == r) {
            tree[v] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) self(self, tree, pos, val, l, mid, v * 2 + 1);
        else self(self, tree, pos, val, mid + 1, r, v * 2 + 2);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    };

    auto query_left = [&](int L, int R) -> ll {
        if (L > R) return 0;
        return query(query, tree_left, L, R, 1, maxv, 0);
    };
    auto query_right = [&](int L, int R) -> ll {
        if (L > R) return 0;
        return query(query, tree_right, L, R, 1, maxv, 0);
    };
    auto update_left = [&](int pos, int val) -> void {
        update(update, tree_left, pos, val, 1, maxv, 0);
    };
    auto update_right = [&](int pos, int val) -> void {
        update(update, tree_right, pos, val, 1, maxv, 0);
    };

    vector<ll> left(n), right(n);

    for (int i = 0; i < n; ++i) {
        int pos = a[i];
        if (pos < 1) pos = 1;
        if (pos > maxv) pos = maxv;
        left[i] = query_left(pos + 1, maxv); 
        update_left(pos, 1);
    }

    for (int i = n - 1; i >= 0; --i) {
        int pos = a[i];
        if (pos < 1) pos = 1;
        if (pos > maxv) pos = maxv;
        right[i] = query_right(1, pos - 1);  
        update_right(pos, 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += left[i] * right[i];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
    return 0;
}

