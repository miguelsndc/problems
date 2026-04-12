#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; ll v; cin >> n; cin >> v;
    vector<ll> t(n), a(n), x(n), y(n);
    for (auto &k: t) cin >> k;
    for (auto &k: a) cin >> k;
    vector<array<ll, 2>> c;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) <= v * t[i]) {
            ll xi = v * t[i] - a[i];
            ll yi = v * t[i] + a[i];
            c.push_back({xi, yi});
        }
    }
    sort(c.begin(), c.end());
    vector<ll> tail;
    for (int i = 0; i < (int)(c.size()); i++) {
        auto it = upper_bound(begin(tail), end(tail), c[i][1]);
        if (it == tail.end()) {
            tail.push_back(c[i][1]);
        } else {
            *it = c[i][1];
        }
    }
    cout << tail.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
