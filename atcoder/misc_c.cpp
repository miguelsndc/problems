#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n), b(n), c(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vi> dp(n, vi(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] += max(dp[i - 1][1], dp[i - 1][0]) + c[i];
    }
    int ans = 0;
    for (int j = 0; j <= 2; j++) ans = max(ans, dp[n - 1][j]);
    cout << ans << '\n';
}