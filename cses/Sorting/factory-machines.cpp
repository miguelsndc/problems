#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> t(n);
    for (auto &x: t) cin >> x;
    ll l = 0, r = 1e18 + 1, ans = 0;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        ll prod = k;
        for (ll i: t) {
            prod -= min(prod, m / i);
        }
        if (prod == 0) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}