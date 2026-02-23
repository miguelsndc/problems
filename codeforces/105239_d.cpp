#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int mxn = 5005;
ll n, a[mxn], dp[mxn][mxn];
ll solve(int l, int r) {
    if (l > r) return 0;
    if (~dp[l][r]) return dp[l][r];
    dp[l][r] = 0;
    ll left = (l + (n - r)) * a[l] + solve(l + 1, r);
    ll right = (l + (n - r)) * a[r] + solve(l, r - 1);
    return dp[l][r] = max(left, right);
}
void dale() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, n - 1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}