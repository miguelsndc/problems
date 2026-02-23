#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++) {
        c[i + 1] = c[i] + (s[i] == '0' ? 1: -1);
    }
    int ma = 0, ans = 0, cnt = count( s.begin(), s.end(), '1');
    for (int i = 0; i <= n; i++) {
        ans = min(ans, c[i] - ma);
        ma = max(ma, c[i]);
    }
    cout << ans + cnt << '\n';
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}
