#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        for (int &i : a) cin >> i;
        for (int &i : b) cin >> i;
        vector<vi> dp(n, vi(2));
        dp[0][1] = dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
                dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
            if (a[i] >= b[i - 1] && b[i] >= a[i - 1])
                dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
            if (b[i] >= a[i - 1] && a[i] >= b[i - 1])
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
            if (b[i] >= b[i - 1] && a[i] >= a[i - 1])
                dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
        }

        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << '\n';
    }
}