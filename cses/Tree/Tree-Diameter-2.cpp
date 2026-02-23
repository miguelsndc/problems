#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 2e5 + 10;
bool chmax(int& a, int b) { return b > a ? a = b, true : false; }
vector<int> g[ms]; pair<int, int> dp[ms];
int ans = 0;
void dfs(int u, int p) {
    dp[u] = { 0, -1 };
    pair<int, int> cur{ 0, -1 };
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        auto old = cur;
        if (chmax(cur.first, 1 + dp[v].first)) {
            if (old.first > 0) cur.second = max(old.first, cur.second);
        }
        else
            chmax(cur.second, 1 + dp[v].first);
    }
    dp[u] = cur;
    ans = max(ans, dp[u].first + max(0, dp[u].second));
}
void dale() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}