#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
int main() {
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    auto get = [&](char c) {
        if (c == 'H') return 0;
        if (c == 'S') return 1;
        return 2;
    };
    vector<vi> g(3, vi());
    g[0] = {1};
    g[1] = {2};
    g[2] = {0};
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = get(c);
    }
    // maximo numero de vitorias se ate i troquei k vezes e o meu card é j
    vector<vi> dp(k + 1, vi(3));
    vector<vi> tmp(k + 1, vi(3));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            for (int c = 0; c < 3; c++)
                dp[j][c] = max(dp[j][c], tmp[j][c]) + (g[c][0] == a[i]);

        for (int j = 0; j < k; j++) {
            for (int c = 0; c < 3; c++) {
                for (int pc = 0; pc < 3; pc++) {
                    if (pc == c) continue;
                        dp[j + 1][c] = max(dp[j + 1][c], tmp[j][pc] + (g[c][0] == a[i]));
                }
            }
        }
        swap(tmp, dp);
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= 2; j++) {
            ans = max(ans, tmp[i][j]);
        }
    }
    cout << ans;
}