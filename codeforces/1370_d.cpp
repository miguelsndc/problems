#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define _sz(x) (int((x).size()))
const int inf = 1e9;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return a < b ? (a = b, true) : false;
}
void arrocha() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int& i : a) cin >> i;
    int l = 1, r = ranges::max(a) + 1, ans = ranges::max(a) + 1;
    auto check_od = [&](int m, bool even) {
        vi pos;
        for (int i = even; i < n; i++)
            if (a[i] <= m) pos.push_back(i);
        if (pos.empty()) return false;
        auto change = [&] (pii x, pii y) -> pii {
            return (x.first >= y.first ? x  : y);
        };
        vi dp(_sz(pos)), pai(n, -1); vector<pii> pref(n);
        int ptr = 0;
        auto chpairmx = [&] (pii &x, pii y) {
            return x.first < y.first ? (x = y, true): false;
        };
        for (int i = 0; i < _sz(pos); i++) {
            while(ptr < pos[i]) chpairmx(pref[ptr + 1], pref[ptr]), ptr++;
            chpairmx(pref[pos[i]], {1, pos[i]});
            chmax(dp[i], 1);
            if (i - 1 >= 0) chmax(dp[i], dp[i - 1]);
            if (pos[i] - 2 >= 0) {
                auto [mx, p] = pref[pos[i] - 2];
                if (chmax(dp[i], mx + 1)) {
                    pai[pos[i]] = p;
                }
                chpairmx(pref[pos[i]], {dp[i], pos[i]});
            }
        }
        int i = -1;
        for (int j = n - 1; j >= 0; j--)
            if (pai[j] != -1) {
                i = j;
                break;
            }

        vector<int> p;
        for (; i != -1; i = pai[i]) {
            p.push_back(i);
        }
        reverse(p.begin(), p.end());
        if (p.empty()) p.push_back(pos[0]);

        int cnt = (even);
        for (int i = 0; i < _sz(p) and cnt < k; i++) {
            cnt++;
            if (p[i] < n - 1 and cnt < k) {
                cnt++;
            }
        }

        return cnt == k;
    };

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check_od(m, 0) or check_od(m, 1)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) arrocha();
}