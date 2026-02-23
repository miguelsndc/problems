#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 1e9 + 7;
void dale() {
    int n; cin >> n;
    vector<string> s(n);
    for (string &x: s) cin >> x;
    string T; cin >> T;
    int m = T.size();
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (string &w: s) {
            if (i < sz(w)) continue;
            bool ok = true;
            for (int x = 0; x < sz(w); x++) {
                char a = w[x];
                char b = T[i - sz(w) + x];
                ok &= (a == b or b == '?');
            }
            if (ok) dp[i] = (dp[i] + dp[i - sz(w)]) % mod;
        }
    }
    cout << dp[m] << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}