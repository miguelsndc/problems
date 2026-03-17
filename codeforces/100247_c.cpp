#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    i64 s; cin >> s;
    i64 ps = 0; map<i64, i64> mp;
    mp[0] = 1;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ps += x;
        if (mp.count(ps -s)) {
            ans += mp[ps - s];
        }
        mp[ps]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
