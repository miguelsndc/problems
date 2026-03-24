#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int ms = 5005;
int a[ms];
i64 dp[ms][ms];
i64 f(int l, int r) {
    if (l > r) return 0;
    i64 &ans = dp[l][r];
    if (~ans) return ans;
    ans = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
    return ans;
}
void solve() {
    int n; cin >> n;
    i64 sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    memset(dp, -1, sizeof dp);
    cout << (sum + f(0, n -1)) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
