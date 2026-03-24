#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<i64> a(n), S(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < (n + 1) / 2; i++) {
        S[i] = a[n - 1 - i] - a[i];
    }
    for (int i = 1; i < n; i++) S[i] += S[i - 1];
    i64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += S[i / 2];
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
