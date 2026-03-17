#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using f64 = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<f64> c(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
    }
    f64 dp = 0.0;
    for (int i = n - 1; i >= 0; i--) {
        f64 pular = dp;
        f64 fazer = c[i] + (1 - p[i]/100.0) *dp;
        dp = max(pular, fazer);
    }
    cout << setprecision(20) << fixed << dp << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
