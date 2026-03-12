#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n; cin >> n;
    i64 d = 1;
    i64 digitosn = to_string(n).length();
    i64 ans = 0;
    i64 currpow = 1;
    while (d < digitosn) {
        ans += 9 * currpow;
        d += 2; 
        currpow *= 100LL;
    }
    if (digitosn & 1) {
        ans += n - currpow + 1;
    }
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
