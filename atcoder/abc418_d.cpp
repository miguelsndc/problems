#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // numero de substrings com impar/par zero terminando em i
    int dp[n + 1][2] = {0};
    for (int i = 1; i <= n; i++) {
        int c = int(s[i - 1] - '0');
        if (c == 0) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i][0];
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}