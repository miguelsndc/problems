#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n + 1), b(n + 1);
    vector dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (abs(a[i] - b[j]) <= 4)});
        }
    }
    cout << dp[n][n];
}