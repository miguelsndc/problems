#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return a < b ? (a = b, true) : false;
}
void dale() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (string& s : g) cin >> s;

    auto faz = [&](int r, int c) -> int {
        bool first = true;
        vector dp(n, vector<int>(m, -1));
        dp[r][c] = 0;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'W') continue;
                int mx_prev = -1;
                if (i + 1 < n and j + 1 < m) {
                    chmax(mx_prev, dp[i + 1][j + 1]);
                }
                if (i + 1 < n) {
                    chmax(mx_prev, dp[i + 1][j]);
                }
                if (i + 1 < n and j - 1 >= 0) {
                    chmax(mx_prev, dp[i + 1][j - 1]);
                }
                if (mx_prev != -1) {
                    chmax(dp[i][j], mx_prev + int(g[i][j] == 'B'));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            chmax(ans, rg::max(dp[i]));
        }
        return ans;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                chmax(ans, faz(i, j));
            }
        }
    }
    cout << ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}