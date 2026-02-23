#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W; cin >> n >> W;
    vi w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    int s = accumulate(all(v), 0);
    vi dp(s + 1, (int)(1e9 + 5));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int c = s; c >= v[i]; c--) {
            dp[c] = min(dp[c], dp[c - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= s; i++) {
        if (dp[i] <= W) ans = i;
    }
    cout << ans;
}