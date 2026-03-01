#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int ms = 3005;
int a[ms], n;
ll dp[ms][ms];
ll solve(int l, int r) {
    if (l > r) return 0;
    ll& ans = dp[l][r];
    if (~ans) return ans;
    ans = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, n - 1);
}
