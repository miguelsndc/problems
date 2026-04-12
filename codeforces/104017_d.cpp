#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<ll> x(m); 
    for (auto &v: p) cin >> v;
    for (auto &v: x) cin >> v;
    const ll inf = 2e18; 
    x.push_back(-inf);
    x.push_back(inf);
    sort(x.begin(), x.end());
    
    struct event {
        ll pos;
        int p;
        bool operator<(const event &other) const { 
            if (pos == other.pos) {
                return p < other.p; 
            }
            return pos < other.pos;
        }
    };
    
    vector<event> sweep;
    for (int i = 0; i < n; i++) {
        ll pos = i * 100;
        auto it = lower_bound(x.begin(), x.end(), pos);
        ll r = *it;
        if (r == pos) continue; 
        ll l = *prev(it);
        ll dist = min(pos - l, r - pos);
        sweep.push_back({pos - dist, p[i]});
        sweep.push_back({pos + dist, -p[i]});
    }

    sort(sweep.begin(), sweep.end());

    ll ans = 0, cur = 0;
    for (auto &[_, val]: sweep) {
        cur += val;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}