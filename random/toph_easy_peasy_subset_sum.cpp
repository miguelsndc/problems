#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int mod = 1e9 + 7;

i64 fexp(i64 a, i64 b) {
    if (b < 0) return 0;
    i64 ans = 1;
    for (; b > 0; b /= 2) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
    }
    return ans;

}

void solve() {
    int n; cin >> n;
    vector<i64> a(n);
    for (auto&x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<i64> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + suf[i + 1] - (n - 1 - i) * a[i] % mod) % mod;
    }
    cout << ans * fexp(2, n - 2) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
