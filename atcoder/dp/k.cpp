#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    // venço ?
    vector<int> dp(k + 1);
    dp[0] = false;
    for (int i = 1; i <= k; i++) {
        for (int x: a) {
            if (i - x >= 0) {
                dp[i] |= !(dp[i - x]);
            }
        }
    }
    if (dp[k]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}
