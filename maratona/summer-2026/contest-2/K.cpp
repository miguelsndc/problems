#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 2e5 + 10;
int a[ms], tree[8 * ms];
void build(int l, int r, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, v * 2 + 1);
        build(mid + 1, r, v * 2 + 2);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
int query(int a, int b, int l, int r, int v = 0) {
    if (b < l or a > r) return 1e9 + 10;
    if (l >= a and r <= b) return tree[v];
    int mid = (l + r) / 2;
    return min(query(a, b, l, mid, v * 2 + 1), query(a, b, mid + 1, r, v * 2 + 2));
}
void dale() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1);
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << query(l, r, 0, n - 1) << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}