#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    i64 tiros = 0, escudo = 0, last = 0;
    for (int i = 0; i < n; i++) {
        int t, d; cin >> t >> d;
        escudo += (t - last);
        if (escudo >= d) {
            escudo -= d;
        } else {
            tiros++;
        }
        last = t;
    }
    cout << tiros << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
