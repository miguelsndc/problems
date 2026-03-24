#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int mxn = 1e6 + 10;
struct node {
    int aberto = 0, fechado = 0, match = 0;
};
node merge(const node &a, const node&b) {
    /*
        juntar a.match e b.match e min(a.aberto, b.fechado)
    */
   node res;
   int novos_match = min(a.aberto, b.fechado);
   res.match = a.match + b.match + novos_match;
   res.aberto = b.aberto + a.aberto - novos_match;
   res.fechado = a.fechado + b.fechado - novos_match;
   return res;
}
node tree[4 * mxn];
void build(string &a, int l, int r, int v = 0) {
    if (l == r) {
        tree[v].aberto = a[l] == '(';
        tree[v].fechado= a[l] == ')';
    } else {
        int mid = (l + r) / 2;
        build(a, l, mid, v * 2 + 1);
        build (a, mid + 1, r, v * 2 + 2);
        tree[v] = merge(tree[v*2+1], tree[v*2+2]);
    }
}
node query(int a, int b, int l, int r, int v = 0) {
    if (b < l || a > r) return node();
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    node left = query(a, b, l, mid, v * 2 + 1);
    node right = query(a, b, mid + 1, r, v * 2 + 2);
    return merge(left, right);
}
void solve() {
    string s; cin >> s;
    int n = (int)(s.size());
    build(s, 0, n - 1);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << query(l, r, 0, n - 1).match * 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
