#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
int m, dp[600][600][600];
int solve(int pedras, int xorsum, int ultimo) {
    if (!pedras) return (xorsum == 0);
    if (~dp[pedras][xorsum][ultimo]) return dp[pedras][xorsum][ultimo];
    dp[pedras][xorsum][ultimo] = 0;
    for (int i = min(pedras, ultimo); i >= 0; i--) {
        dp[pedras][xorsum][ultimo] = (dp[pedras][xorsum][ultimo] + solve(pedras - i,  xorsum ^ i, i));
        if (dp[pedras][xorsum][ultimo] >= m) dp[pedras][xorsum][ultimo] -= m;
    }
    return dp[pedras][xorsum][ultimo];
};
void dale() {
    memset(dp, -1, sizeof dp);
    int n, p, m; cin >> n >> p >> m;
    cout << solve(n - p, p, n - p) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}