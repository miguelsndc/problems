#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n), v(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for(i64 i = 0; i < n; i++) {
        v[i] = (i + 1) * (n - i) * a[i];
    }
    sort(v.begin(), v.end());
    sort(b.rbegin(), b.rend());
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + v[i] % mod * b[i]) % mod;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
