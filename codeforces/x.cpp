#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int a, b; cin >> a >> b;
    if (a == 0 and b == 0) {
        cout << "YES\n";
        return;
    }
    if (a > 0 and b > 0 and (a + b) % 3 == 0 and max(a,b) <= 2 * min(a,b)) {
        cout << "YES\n";
    }  else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1 ;cin >> tt;
    while(tt--) solve();
}
