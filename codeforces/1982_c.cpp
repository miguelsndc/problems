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
        int n, l, r; cin >> n >> l >> r;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        vector<ll> dp(n + 1), ps(n + 1);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
        int s = 0, j = -1;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            if (j < i)  {
                j = i;
                s = 0;
            }
            while(j < n and s < l) s += a[j++];
            if (s >= l and s <= r) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
            s -= a[i];
        }
        cout << dp[n] << '\n';
    }
}