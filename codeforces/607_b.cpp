#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return a > b ? (a = b, true) : false;
}
void dale() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector dp(n, vector<int>(n, -1));
    auto solve = [&](auto&& solve, int l, int r) -> int {
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        int cost = 1 + solve(solve, l + 1, r);
        if (a[l] == a[l + 1]) chmin(cost, 1 + solve(solve, l + 2, r));
        for (int k = l + 2; k <= r; k++) {
            if (a[l] == a[k]) {
                chmin(cost, solve(solve, l + 1, k - 1) + solve(solve, k + 1, r));
            }
        }
        return dp[l][r] = cost;
    };
    cout << solve(solve, 0, n - 1) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}