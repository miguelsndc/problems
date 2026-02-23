#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    int operator()(pii x) const { return x.first* 31 + x.second; }
};
void dale() {
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
    vector<pii> queries(q);
    for (auto& [x, y] : queries) cin >> x >> y;
    unordered_map<pii, int, chash> mp, ans;
    for (int i = 0; i < q; i++) {
        mp[{queries[i].first, queries[i].second}] = i;
    }
    auto d = [&] (ll x1, ll x2, ll y1, ll y2) -> ll {
        return 1ll * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    for (int i = 0; i < n; i++) {
        for (int u = x[i] - r[i]; u <= x[i] + r[i]; u++) {
            for (int v = y[i] - r[i]; v <= y[i] + r[i]; v++) {
                if (mp.find({u, v}) != mp.end()) {
                    if (d(x[i], u, y[i], v) <= 1ll * r[i] * r[i]) ans[{u, v}]++;
                }
            }
        } 
    }
    for (int i = 0; i < q; i++) {
        if (ans.find(queries[i]) != ans.end()) {
            cout << ans[queries[i]] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}