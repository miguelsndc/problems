#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int x, y; cin >> x >> y;
    if (y > 0) {
        x -= 2 * y;
        y = 0;
    } else if (y < 0) {
        x -= 4 * abs(y);
        y = 0;
    }

    if (x >= 0 and x % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while(tt--) solve();
}
