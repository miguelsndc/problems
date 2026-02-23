#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int maxn = 3005;
ll a[maxn], dp[maxn][maxn];
ll solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    ll ans = 0;
    ans = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
    return dp[l][r] = ans;;
}
void dale() {
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1);
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
