#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int ms = 2e5 + 10, mod = 1e9 + 7;
int n, a[ms], m;
void add(i64 &x, i64 y) {
    x += y;
    if (x >= mod) x -= mod;
}
struct node {
    i64 l = 0, r = 0;
    vector<i64> dp;
    node() { dp.assign(m + 1, 0); }
    node(int l, int r) : l(l), r(r) {
        dp.assign(m + 1, 0);
        if (l == -1) return;
        dp[0] = 1;
        add(dp[a[l] % m], 1);
    }
};
vector<node> tree(4 * ms);
node join(const node& a, const node& b) {
    if(a.l == -1) return b;
    if (b.l == -1) return a;
    node ans;
    ans.l = a.l, ans.r = b.r;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            add(ans.dp[(i + j) % m], (a.dp[i] * b.dp[j]) % mod);
        }
    }

    return ans;
}
void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = node(l, r);
        return;
    } else {
        int mid = l + (r - l) / 2;
        build(l, mid, v * 2 + 1);
        build(mid + 1, r, v * 2 + 2);
        tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

node query(int a, int b, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return node(-1, -1);
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    node left = query(a, b, l, mid, v * 2 + 1);
    node right = query(a, b, mid + 1, r, v * 2 + 2);
    return join(left, right);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto res = query(l, r).dp[0];
        cout << (res)  << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
