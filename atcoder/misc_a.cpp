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
    int n; cin >> n;
    vi h(n), dp(n, (int)(1e9));
    for (int &i: h) cin >> i;
    dp[0] = 0;
    // for (int i = 0; i + 1< n; i++) {
    //         dp[i + 1] = min(dp[i] + abs(h[i] - h[i + 1]), dp[i + 1]);
    //     if (i + 2 < n) 
    //         dp[i + 2] = min(dp[i] + abs(h[i] - h[i + 2]), dp[i + 2]);
    // ;}
    // cout << dp[n - 1] << '\n';
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i - 2 >= 0) 
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1];
}