#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int n;
const int maxn = 305;
double dp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
double solve(int x, int y, int z) {
    if (x < 0 or y < 0 or z < 0) return 0.0;
    if (x == 0 and y == 0 and z == 0) return 0.0;
    if (vis[x][y][z]) return dp[x][y][z];
    vis[x][y][z] = true;
    double ans = n;
    if (x > 0) ans += x * solve(x - 1, y, z);
    if (y > 0) ans += y * solve(x + 1, y - 1, z);
    if (z > 0) ans += z * solve(x, y + 1, z - 1);
    return dp[x][y][z] = ans / (x + y + z + 0.0);
}
void dale() {
    memset(vis, 0, sizeof vis);
    cin >> n;
    int cnt[4] = {0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    cout << fixed << setprecision(10) << solve(cnt[1], cnt[2], cnt[3]);
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;// cin >> tt;
    while(tt--) dale();
}
