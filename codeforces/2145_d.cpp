#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int maxk = n * (n - 1) / 2;
        vector dp(n + 1, vector<int>(maxk + 1));
        vector p(n + 1, vector<int>(maxk + 1, -1));

        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int x = 0; x <= maxk; x++) {
                for (int y = 1; y <= n - i; y++) {
                    if (!dp[i][x]) continue;
                    int add = y * (y - 1) / 2;
                    dp[i + y][x + add] = 1;
                    p[i + y][x + add] = y;
                }
            }
        }
        k = maxk - k;
        if (dp[n][k]) {
            vector<int> ans;
            int cur = n, curk = k;
            while (cur != 0) {
                int y = p[cur][curk];
                ans.push_back(y);
                curk -= y * (y - 1) / 2;
                cur -= y;
            }
            vector<int> res;
            cur = n + 1;
            for (int y : ans) {
                for (int x = cur - y; x < cur; x++) {
                    res.push_back(x);
                }
                cur -= y;
            }
            for (int i = 0; i < (int)(res.size()); i++) {
                cout << res[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}