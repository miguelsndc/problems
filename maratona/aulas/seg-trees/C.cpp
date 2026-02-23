#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int ms = 2e5 + 10;
ll lazy[4 * ms], folhas[ms];
void push(int v) {
    int left = v * 2 + 1, right = v * 2 + 2;
    lazy[left] += lazy[v];
    lazy[right] += lazy[v];
    lazy[v] = 0;
}
ll get(int idx, int l, int r, int v = 0) {
    if (l == r) {
        return folhas[idx] + lazy[v];
    }
    push(v);
    int m = (l + r) / 2;
    if (idx <= m) {
        return get(idx, l, m, v * 2 + 1);
    } else {
        return get(idx, m + 1, r, v * 2 + 2);
    }
}
void update(int a, int b, int l, int r, int add, int v = 0) {
    if (b < l or a > r) return;
    if (a <= l and r <= b) {
        lazy[v] += add; 
        return;
    }
    push(v);
    int m = (l + r) / 2;
    update(a, b, l, m, add, v * 2 + 1);
    update(a, b, m + 1, r, add, v * 2 + 2);
}
void dale() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> folhas[i];
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, u; cin >> a >> b >> u;
            --a, --b;
            update(a, b, 0, n - 1, u);
        } else {
            int k; cin >> k; --k;
            cout << get(k, 0, n - 1) << '\n';
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    while(tt--) dale();
}