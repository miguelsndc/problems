#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(n + 1, int(1e9 + 1)), mx(n + 1, int(1e9 + 1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i - 1] + 1, mx[a[i]]);
        mx[a[i]] = min(mx[a[i]], dp[i - 1]);
    }
    cout << n - dp[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}