#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
double dp[305][305][305], sz;
double f(int x, int y, int z) {
    if (x == 0 and y == 0 and z == 0) return 0;
    double &ans = dp[x][y][z];
    if (ans >= 0) return ans;
    ans = sz; double s = x + y + z;
    if (x > 0) ans += x * f(x - 1, y, z);
    if (y > 0) ans += y * f(x + 1, y - 1, z);
    if (z > 0) ans += z * f(x, y + 1, z - 1);
    return dp[x][y][z] = ans /= s;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    sz = n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int x = ranges::count(a, 1);
    int y = ranges::count(a, 2);
    int z = ranges::count(a, 3);
    memset(dp, -1, sizeof dp);
    cout << setprecision(20) << fixed << f(x, y, z) << '\n';
}
