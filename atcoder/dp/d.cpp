#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<ll> dp(W + 1);
    for (int i = 0; i < n; i++) {
        for (int c = W; c >= 0; c--) {
            if (c - w[i] >= 0) dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
