#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        if (i % 2 == 0) a[i] = mx;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i += 2) {
        if (i == 1) {
            if (a[i] >= a[i + 1]) {
                ans += (a[i] - a[i + 1]) + 1;
            }
        } else if (i == n) {
            if (a[i] >= a[i - 1]) {
                ans += (a[i] - a[i - 1]) + 1;
            }
        } else if (i - 1 >= 1 and i + 1 <= n) {
            int x = min(a[i - 1], a[i + 1]);
            if (a[i] >= x) {
                ans += (a[i] - x) + 1;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}