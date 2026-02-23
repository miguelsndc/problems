#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 2e5 + 10;
int n, k;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return a < b ? (a = b, true) : false;
}
vector<pair<int, int>> g[mxn];
int cnt = 0;
ll limit = 0;
ll dfs(int u, int p = -1) {
    ll mx1 = 0, mx2 = 0;
    for (auto [v, w] : g[u]) {
        if (v == p) continue;
        ll dist = dfs(v, u) + w;
        if (dist > limit) {
            dist = w;
            cnt++;
        }
        ll prev = mx1;
        if (chmax(mx1, dist)) {
            mx2 = prev;
        } else {
            chmax(mx2, dist);
        }
    }
    if (mx1 + mx2 > limit) {
        cnt++;
        return 0;
    }
    return mx1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    ll c = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
        c = max(c, (ll)w);
    }
    ll l = c, r = 1e15, ans = 1e15;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        limit = m;
        cnt = 0;
        dfs(1);
        if (cnt <= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}