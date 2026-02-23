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
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        vector<ll> ps(n + 1), dp(n + 1);
        map<ll,ll> mp;
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
        mp[0ll] = 1ll;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (mp.count(ps[i])) {
                dp[i] = max(dp[i], dp[mp[ps[i]]] + 1);
            }
            mp[ps[i]] = i;
        }
        cout << dp[n] << '\n';
    }
}
//