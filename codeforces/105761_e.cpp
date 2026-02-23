#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 1e9 + 7;
void dale() {
    int n, k, s; cin >> n >> k >> s;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if ((a[j] - a[i]) <= k and (j - i + 1) <= s) {
                (dp[i] += (dp[j + 1]) % mod) %= mod;
            }
        }
    }
    cout << dp[0] << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}