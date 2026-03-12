#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

#define ll long long
#define pii pair<ll, ll>
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v))

struct BIT2D {
    vector<ll> ord;
    vector<vector<ll>> bit, coord;

    BIT2D(vector<pii> pts) {
        sort(begin(pts), end(pts));

        for (auto [x, y] : pts)
            if (ord.empty() || x != ord.back()) ord.push_back(x);

        bit.resize(ord.size() + 1);
        coord.resize(ord.size() + 1);

        sort(begin(pts), end(pts),
             [&](pii& a, pii& b) { return a.second < b.second; });

        for (auto [x, y] : pts)
            for (int i = upper(ord, x); i < bit.size(); i += i & -i)
                if (coord[i].empty() || coord[i].back() != y)
                    coord[i].push_back(y);

        for (int i = 0; i < bit.size(); i++)
            bit[i].assign(coord[i].size() + 1, 0);
    }

    void update(ll X, ll Y, ll v) {
        for (int i = upper(ord, X); i < bit.size(); i += i & -i)
            for (int j = upper(coord[i], Y); j < bit[i].size(); j += j & -j)
                bit[i][j] = max(bit[i][j], v);
    }

    ll query(ll X, ll Y) {
        ll sum = 0;
        for (int i = upper(ord, X); i > 0; i -= i & -i)
            for (int j = upper(coord[i], Y); j > 0; j -= j & -j)
                sum = max(sum, bit[i][j]);
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> posA(n + 1), posB(n + 1);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        posA[v] = i;
    }
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        posB[v] = i;
    }
    vector<pii> pts;
    for (int v = 1; v <= n; v++) {
        pts.push_back({posA[v], posB[v]});
    }
    BIT2D bit2d(pts);
    int ans = 0;
    for (int v = 1; v <= n; v++) {
        int x = posA[v], y = posB[v];
        int mx = bit2d.query(x - 1, y - 1);
        ans = max(ans, mx + 1);
        bit2d.update(x, y, mx + 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
}
