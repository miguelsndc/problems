#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return a > b ? (a = b, true) : false;
}
void dale() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int& i : a) cin >> i;
    for (int& i : c) cin >> i;
    vector<int> b = a;
    rg::sort(b);
    rg::unique(b);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    const ll inf = 1e18;
    vector<ll> dp(sz(b), inf);
    // auto solve = [&](auto&& f, int i, int prev) -> int {
    //     if (i == n) return 0;
    //     if (dp[i][prev] != -1) return dp[i][prev];
    //     ll cost = 1e18;
    //     for (int j = 0; j < sz(b); j++) {
    //         if (j >= prev) {
    //             ll add = (a[i] == j ? 0 : c[i]);
    //             cost = min(cost, add + f(f, i + 1, j));
    //         }
    //     }
    //     return dp[i][prev] = cost;
    // };
    for (int j = 0; j < n; j++) dp[j] = (a[0] == j ? 0 : c[0]);
    for (int i = 1; i < n; i++) {
        vector<ll> nxt(sz(b), inf);
        vector<ll> pref(sz(b));
        pref[0] = dp[0];
        for (int j = 1; j < sz(b); j++) pref[j] = min(pref[j - 1], dp[j]);

        for (int j = 0; j < sz(b); j++) {
            ll add = (a[i] == j ? 0 : c[i]);
            nxt[j] = pref[j] + add;
        }
        swap(dp, nxt);
    }
    cout << rg::min(dp) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}