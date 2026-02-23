#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m));
    int mx = 0;
    for (auto& v : g)
        for (int& i : v) cin >> i, mx = max(mx, i);
    int l = 0, r = mx + 1, ans = mx + 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        vector dp(n, vector<int>(m, -1));
        vector<pii> dirs = {{1, 0}, {0, -1}, {0, 1}};
        auto solve = [&] (auto&&f, int i, int j) -> bool {
            if (i == n - 1 and j == m - 1) return dp[i][j] = true;
            if (dp[i][j] != -1) return dp[i][j];
            dp[i][j] = false;
            for (auto [dx, dy]: dirs) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni >= 0 and ni < n and nj >= 0 and nj < m and g[ni][nj] <= mid and dp[ni][nj] == -1) {
                    dp[i][j] |= f(f, ni, nj);
                }
            }
            return dp[i][j];
        };
        solve(solve, 0, 0);
        if (dp[0][0] == true) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}