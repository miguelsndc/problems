#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using f64 = long double;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    f64 k, p, x; cin >> k >> p >> x;  
    auto f = [&] (i64 m) -> f64 {
        return ((f64)m) * x + (k / ((f64)m)) * p;
    };
    
    i64 lo = 0, hi = 1e18;
    while(hi - lo > 3) {
        i64 m1 = lo + (hi - lo) / 3;
        i64 m2 = hi - (hi - lo) / 3;
        if (f(m1) > f(m2)) {
            lo = m1;
        } else {
            hi = m2;
        }
    }
    i64 ans = lo;
    for (i64 i = lo + 1; i <= hi; i++) {
        if (f(i) < f(ans)) {
            ans = i;
        }
    }
    cout << setprecision(3) << fixed << f(ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
