#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll full = (1LL << k) - 1;
    int f = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == full) f++;
    }
    ll included = 0;
    for (int bit = k - 1; bit >= 0; bit--) {
        bool can = true;
        for (int i = 0; i < n; i++) {
            if ((a[i] & (1LL << bit)) == 0) {
                if ((a[i] & included) != included) {
                    can = false;
                    break;
                }
            }
        }
        if (can) {
            included |= (1LL << bit);
        }
    }
    if (f > 0 && included == full) {
        included &= ~1LL;
    }
    cout << included << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}