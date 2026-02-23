#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll ans = max(min(r1, r2) - max(l1, l2) + 1, 0ll);
        ll pw = k;
        for (int i = 1; i <= 32; i++) {
            if (pw > (1e9)) break;

            ll p2 = ((l2 + pw - 1) / pw) * pw;
            ll u2 = (r2 / pw) * pw;

            if (p2 / pw < l1) {
                p2 = l1 * pw;
            }
            if (u2 / pw > r1) {
                u2 = r1 * pw;
            }

            ll len = u2 - p2;
            ans += max(0ll, len / pw + 1);
            if (pw > (ll)1e9 / k) break;
            pw *= k;
        }

        cout << ans << '\n';
    }
}