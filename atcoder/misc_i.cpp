#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector dp(n, vector<double>(n + 1));
    // probabilidade ter j heads up to i
    /*
        1 probabilidade p[i]
        dp[i][1] = p[1]
        se eu adiciono outra moeda to em i + 1
        passa por todo k < j multiplica por dp[i - 1][k]
    */
    dp[0][1] = p[0];
    dp[0][0] = (1 - p[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        for (int j = 1; j <= i+1; j++) {
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
        }
    }
    double ans = 0;
    for (int i = n; i > n / 2; i--) {
        ans += dp[n - 1][i];
    }
    cout << fixed << setprecision(10) << ans;
}