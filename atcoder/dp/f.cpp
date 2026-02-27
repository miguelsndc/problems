#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    string lcs; int i = n, j = m;
    while(lcs.size() < dp[n][m]) {
        if (s[i - 1] == t[j - 1]) {
            lcs += s[i - 1];
            i--, j--;
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                i--;
            } else if (dp[i][j - 1] == dp[i][j]) {
                j--;
            } else {
                i--, j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
}
