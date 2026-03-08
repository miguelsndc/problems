#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int n; vector<ll> tree;
ll join(ll a, ll b) {
    return max(a,b);
}
void update(int pos, ll val, int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = val;
        return;
    } else {
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, v * 2 + 1);
        } else {
            update(pos, val, mid + 1, r, v * 2 + 2);
        }
        tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

ll query(int a, int b, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    ll left = query(a, b, l, mid, v * 2 + 1);
    ll right = query(a, b, mid + 1, r, v * 2 + 2);
    return join(left, right);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> h(n), a(n);
    tree.assign(4 * n, 0);
    for (int i = 0; i < n; i++) cin >> h[i], --h[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> dp(n);
    dp[n - 1] = a[n - 1];
    update(h[n - 1], a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = query(h[i] + 1, n - 1) + a[i];
        update(h[i], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
}
