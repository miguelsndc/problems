#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

#include <vector>
#include <algorithm>

using namespace std;

struct merge_sort_tree {
    int n;
    vector<vector<int>> tree;

    merge_sort_tree(const vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, {});
        if (n) build(a, 0, n - 1, 0);
    }

    int query(int ql, int qr, int k) {
        return n ? query_node(ql, qr, k, 0, n - 1, 0) : 0;
    }

private:
    void build(const vector<int>& a, int l, int r, int v) {
        if (l == r) return void(tree[v].push_back(a[l]));
        int m = l + (r - l) / 2;
        build(a, l, m, v * 2 + 1);
        build(a, m + 1, r, v * 2 + 2);
        tree[v].resize(tree[v * 2 + 1].size() + tree[v * 2 + 2].size());
        merge(tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(),
              tree[v * 2 + 2].begin(), tree[v * 2 + 2].end(),
              tree[v].begin());
    }

    int query_node(int ql, int qr, int k, int l, int r, int v) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) 
            return upper_bound(tree[v].begin(), tree[v].end(), k) 
                 - lower_bound(tree[v].begin(), tree[v].end(), k);
        int m = l + (r - l) / 2;
        return query_node(ql, qr, k, l, m, v * 2 + 1) + 
               query_node(ql, qr, k, m + 1, r, v * 2 + 2);
    }
};

struct sparse_table {
    int n;
    vector<vector<int>> table;
    int merge(int x, int y) {
        return gcd(x, y);
    }
    sparse_table(vector<int> &a): n(a.size()), table(__lg(n) + 1, vector<int>(n)) {
        for (int i = 0; i < n; ++i) table[0][i] = a[i];
        for (int i = 1; i <= __lg(n); ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int i, int j) {
        int k = __lg(j - i + 1);
        return merge(table[k][i], table[k][j - (1 << k) + 1]);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    sparse_table st(a);
    merge_sort_tree mst(a);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r; --l, --r;
        int g = st.query(l, r);
        cout << (r - l + 1) - mst.query(l, r, g) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
