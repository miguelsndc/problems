#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, k; cin >> n >> m >> k;
    vector <int> weight(n), cost(n);
    for (int &i: weight) cin >> i;
    for (int &i: cost) cin >> i;
    const ll inf = 1e15;
    vector dp(m + 1, vector<ll>(k + 1, inf)), prev(m + 1, vector<ll>(k + 1, inf));
    prev[0][0] = 0;
    for (int x = 1; x <= n; x++) { 
        dp = prev;
        for (int y = 0; y <= m; y++) {
            for (int z = 0; z <= k; z++) {
                if (y >= weight[x - 1] and z >= cost[x - 1]) {
                    dp[y][z] = min(dp[y][z], dp[y - weight[x - 1]][z - cost[x - 1]] + 1);
                }
            }
        }
        prev = dp;
    }
    ll ans = inf;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dp[m][i]);
    }
    cout << (ans == inf ? -1 : ans);
}
