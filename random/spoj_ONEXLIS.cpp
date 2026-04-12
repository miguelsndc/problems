#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()
struct segment_tree {
    int n;
    vector<int> tree;
    int merge(int x, int y) {
        return max(x, y);
    }
    segment_tree(int n): n(n), tree(2 * n) {}
    void update(int i, int x) {
        tree[i += n] = x;
        while (i >>= 1) tree[i] = merge(tree[i << 1], tree[(i << 1) | 1]);
    }
    int query(int i, int j) {
        int l = 0, r = 0;
        for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) l = merge(l, tree[i++]);
            if (j & 1) r = merge(tree[--j], r);
        }
        return merge(l, r);
    }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<int> dp_fw(n), dp_bw(n), tail;
    for (int i = 0; i < n; i++) {
        int v = a[i];
        auto it = lower_bound(tail.begin(), tail.end(), v);
        int pos = it - tail.begin();
        if (it == tail.end()) {
             tail.push_back(v);
        } else {
            *it = v;
        }
        dp_fw[i] = pos + 1;
    }
    tail.clear();
    for (int i = n - 1; i >= 0; i--) {
        int v = -a[i];
        auto it = lower_bound(tail.begin(), tail.end(), v);
        int pos = it - tail.begin();
        if (it == tail.end()) {
            tail.push_back(v);
        } else {
            *it = v;
        }
        dp_bw[i] = pos + 1;
    }
    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {a[i], i};
    }
    sort(v.rbegin(), v.rend());
    /*
        queremos i < j com a[i] > a[j] somar dp_fw[i] + dp_bw[j]
        fixa i 
    */
    segment_tree seg(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x, j] = v[i];
        if (j > 0) {
            int best = seg.query(0, j - 1);
            if ( best > 0) ans = max(ans, best + dp_bw[j]);
        }
        seg.update(j, dp_fw[j]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
