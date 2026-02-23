#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n, p;
    cin >> n >> p;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        __int128_t ways = 1, cur = 1;
        bool ok = false;
        if (ways >= n) ok = true;
        for (int i = 1; i <= min(p, n) and !ok; i++) {
            cur = cur * (m - i + 1);
            cur /= i;
            ways += cur;
            if (ways >= n) {
                ok = true;
            }
        }
        if (ok) {
            ans = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}