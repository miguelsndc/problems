#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) {
        string s; cin >> s;
        int n = s.size();
        vector dp(n, vector<int>(n, -1));
        auto solve =[&] (auto &solve, int l, int r) -> int {
            if (l >= r) return 0;
            if (~dp[l][r]) return dp[l][r];
            int cost = 1 + solve(solve, l + 1, r);
            cost = min(cost, 1 + solve(solve, l, r - 1));
            cost = min(cost, (s[l] != s[r]) + solve(solve, l + 1, r - 1));
            return dp[l][r] = cost;
        };
        cout << solve(solve, 0, n - 1) << '\n';
    }
}