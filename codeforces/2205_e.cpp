#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod =  998244353;
void bop()
{
    /*
    vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
    }
    */
    int n;
    cin >> n;
    vector<int> T(n);
    for (auto& i : T)
        cin >> i;
    vector lps(n, vector<int>(n));
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int j = lps[l][r - 1];
            while(j > 0 and T[r] != T[l + j]) {
                j = lps[l][l + j - 1];
            }
            if (T[l + j] == T[r]) j++;
            lps[l][r] = j;
        }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        if (lps[0][i] == 0) dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (lps[j + 1][i] == 0) {
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
    }
    cout << dp[n - 1] <<  '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        bop();
}