#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll r = 1;
    ll ans = (1ll << 61);
    for (ll i = 1; i <= n; i++) {
        ans = min(ans, (i - 1) * a[i] + (n - i) * a[i]);
    }
    for (ll l = 1; l <= n; l++) {
        while(r + 1 <= n and a[r + 1] == a[l]) r++;
        ans = min(ans, (l - 1) * a[l] + (n - r) * a[r]);
    }
    cout << ans << '\n';
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) dale();
}
