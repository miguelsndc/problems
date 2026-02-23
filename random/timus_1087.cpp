#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, m; cin >> n >> m;
    vector<int> k(m);
    for (int &i: k) cin >> i;
    vector<int> dp(n + 1);
    // 1 - win state 0 - lose state
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j: k) {
            if (i - j >= 0) {
                dp[i] |= !dp[i - j];
            }
        }
    }
    if (dp[n]) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}