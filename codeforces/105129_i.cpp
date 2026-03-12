#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, m, k; cin >> n >> m >> k;
    vector<i64> a(n);
    i64 ans = 0;
    for (auto &x: a) cin >> x;
    for (auto x: a) {
        i64 cur = 0;
        if (x % m == 0) {
            cur = x / m;
        } else {
            cur = max(cur, (x - k) / m);
        }
        ans += cur;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
