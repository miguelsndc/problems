#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int move: {2, 3, 5}) {
            if (i - move >= 0) {
                dp[i] &= !(dp[i - move]);
            }
        }
    }
    if (!dp[n]) {
        cout << "First\n"; 
    } else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
