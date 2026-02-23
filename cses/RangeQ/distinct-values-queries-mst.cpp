#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
int n, q, a[maxn];
vector tree(4 * maxn, vector<int>());
/*
merges a and b into sink
*/
void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v].push_back(a[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        tree[v].resize(tree[v * 2 + 1].size() + tree[v * 2 + 2].size());
        merge(tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(),
              tree[v * 2 + 2].begin(), tree[v * 2 + 2].end(),
              tree[v].begin());
    }
}
int query(int a, int b, int l = 0, int r = n - 1, int v = 0) {
    if (b < l or a > r) return {};
    if (a <= l and r <= b) {
        // maior queb
        return int(tree[v].end() - upper_bound(tree[v].begin(), tree[v].end(), b));
    }
    int m = (l + r) / 2;
    int left = query(a, b, l, m, v * 2 + 1);
    int right = query(a, b, m + 1, r, v * 2 + 2);
    return left + right;
}
void dale() {
    cin >> n >> q;
    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> occ;
    for (int i = n - 1; i >= 0; i--) {
        if (!occ.count(b[i])) {
            a[i] = n;
        } else {
            a[i] = occ[b[i]];
        }
        occ[b[i]] = i;
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << query(l, r) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}