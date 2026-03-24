#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n; cin >> n;
    long double sum = 0;
    for (i64 x = 0; x <= n; x++) {
        sum += x * (x - 1);
    }
    cout << setprecision(20) << fixed << sum / (n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
