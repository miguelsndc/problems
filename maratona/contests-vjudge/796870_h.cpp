#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
using f64 = long double;
void solve() {
    vector<f64> p(7);
    for (int i = 1; i <= 6; i++) cin >> p[i];
    f64 expected = 0;
    for (int i = 1; i <= 6; i++) {
        expected += i * p[i];
    }
    f64 ans = 1e9;
    for (int i = 1; i <= 6; i++) {
        f64 novo = (3.5L + i * p[i] - expected) / p[i];
        if (fabs(novo - (f64)(i)) < ans) {
            ans = fabs(novo - (f64)(i));
        }
    }
    cout << setprecision(3) << fixed << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
