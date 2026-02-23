#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int maxn = 1e6 + 5, mod = 1e9 + 7;
ll fat[maxn], dp[maxn];
void dale() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    ll term = fat[n] * (n - 1) % mod;
    ll ans = (term - dp[n] + mod) % mod; 
    cout << ans << '\n';
}
int main(){
    fat[0] = 1;
    dp[0] = dp[1] = 0;
    for (ll i = 1; i < maxn; i++) (fat[i] = fat[i - 1] * i % mod);
    for (ll i = 2; i < maxn; i++) {
        dp[i] = (i * dp[i - 1] + fat[i - 1]) % mod;
    }
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}