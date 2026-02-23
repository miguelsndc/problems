#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define sz(x) (int((x).size()))
void dale() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> v;
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        ll d = a - b;
        v.emplace_back(d, a, b);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto [d, a, b]: v) {
        if (a > n) continue;
        ll x = (n - a) / d + 1;
        ans += x;
        n -= x * d;
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}