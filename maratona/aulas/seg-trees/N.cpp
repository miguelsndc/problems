#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
vector<int> tree[4 * maxn];
int a[maxn];
void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v].push_back(a[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        int i = 0, j = 0;
        while (i < tree[v * 2 + 1].size() and j < tree[v * 2 + 2].size()) {
            if (tree[v * 2 + 1][i] < tree[v * 2 + 2][j])
                tree[v].push_back(tree[v * 2 + 1][i++]);
            else
                tree[v].push_back(tree[v * 2 + 2][j++]);
        }
        while (i < tree[v * 2 + 1].size())
            tree[v].push_back(tree[v * 2 + 1][i++]);
        while (j < tree[v * 2 + 2].size())
            tree[v].push_back(tree[v * 2 + 2][j++]);
    }
}

int query(int a, int b, int x, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 0;
    if (l >= a and r <= b) {
        return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
    }
    int m = (l + r) / 2;
    int half1 = query(a, b, x, l, m, v * 2 + 1);
    int half2 = query(a, b, x, m + 1, r, v * 2 + 2);
    return half1 + half2;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n; int m; cin >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    int mn = *min_element(a, a + n), mx = *max_element(a, a + n);
    while(m--) {
        int l, r, k; cin >> l >> r >> k;
        --l, --r;
        int ans = 0;
        int lo = mn, hi = mx;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int quantos = query(l, r, mid);
            if(quantos >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}