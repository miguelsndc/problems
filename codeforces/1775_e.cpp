#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<i64> ps(n + 1);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
    i64 mx = *max_element(ps.begin(), ps.end());
    i64 mn = *min_element(ps.begin(), ps.end());
    cout << mx - mn << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
