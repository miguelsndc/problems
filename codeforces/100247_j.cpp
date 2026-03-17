#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    int ans = 0, k = 0;
    for (auto &[x, y]: a) {
        if (x > k and y > ans) {
            ans = y;
        }
        k = max(k, x);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
