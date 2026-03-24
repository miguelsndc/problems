#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, c, k; cin >> n >> c >> k;
    vector<i64> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    i64 ans = c;
    for (auto x: a) {
        if (x <= ans) {
            i64 precisa = ans - x, vai = min(k, precisa);
            x += vai;
            k -= vai;
            ans += x;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
