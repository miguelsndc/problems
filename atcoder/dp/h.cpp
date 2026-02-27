#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto& s : grid) cin >> s;
    vector dp(h + 1, vector<int>(w + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (grid[i - 1][j - 1] == '#') continue;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[h][w] << '\n';
}
