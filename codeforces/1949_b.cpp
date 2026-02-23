#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dale() {
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    ll ans = 0;
    for (int t = 0; t <= n; t++) {
        ll mn = LLONG_MAX;
        for (int i = 1; i <= t; i++) mn = min(mn, b[i + n - t] - a[i]);
        for (int i = t+1; i <= n; i++) mn = min(mn, a[i] - b[i - t]);
        ans = max(ans, mn);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) dale();
}
