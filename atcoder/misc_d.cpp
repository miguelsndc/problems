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
    int n, W; cin >> n >> W;
    vi w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(W + 1);
    for (int i = 0; i < n; i++) {
        for (int c = W; c >= w[i]; c--) {
            dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    cout << dp[W];
}