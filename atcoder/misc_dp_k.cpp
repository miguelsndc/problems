#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int maxn = 105, maxk = 1e5 + 5;
int n, k, a[maxn], dp[maxk];
void dale() {
    memset(dp, 0, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) {
                dp[i] |= (dp[i - a[j]]) ^ 1;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second" )<< '\n';
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;// cin >> tt;
    while(tt--) dale();
}
