#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int ans = 0, swap = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            ans += swap;
            swap = false;
        } else {
            swap = true;
        }
    }
    if (swap) ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
