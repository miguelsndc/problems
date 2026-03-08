#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ninf = -1e9;
struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, ninf);
    }
    // add val at position pos (0-based)
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] = max(bit[i], val);
    }
    // sum [0..pos] (0-based)
    int sum(int pos) const {
        if (pos < 0) return ninf;
        int s = ninf;
        for (int i = pos + 1; i > 0; i -= i & -i) s = max(s, bit[i]);
        return s;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, L;
    cin >> n >> L;
    vector<vector<int>> perms(n + 1);
    vector<int> C(n + 1);
    perms[0].resize(L);
    iota(perms[0].begin(), perms[0].end(), 0);
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        for (int j = 0; j < L; j++) {
            int x;
            cin >> x;
            perms[i].push_back(--x);
        }
    }
    auto dist = [&](int i, int j) {
        vector<int> A = perms[i], B = perms[j], P(L);
        for (int i = 0; i < L; i++) {
            P[A[i]] = i;
        }
        for (int i = 0; i < L; i++) {
            B[i] = P[B[i]];
        }
        int cnt = 0;
        for (int i = L - 1; i >= 0; i--) {
            for (int j = L - 1; j > i; j--) {
                cnt += (B[i] > B[j]);
            }
        }
        return cnt;
    };
    BIT bit(n + 5);
    vector<int> dp(n + 1, ninf);
    int ans = 0;
    dp[0] = 0;
    bit.add(0, 0);
    for (int i = 1; i <= n; i++) {
        if (i - 36 >= 0) {
            int best = bit.sum(i - 36);
            if (best >= 0) dp[i] = max(dp[i], bit.sum(i - 36) + C[i]);
        }
        for (int j = max(i - 35, 0); j < i; j++) {
            if (dist(i, j) <= i - j and dp[j] >= 0)
                dp[i] = max(dp[i], dp[j] + C[i]);
        }
        if (dp[i] >= 0) {
            bit.add(i, dp[i]);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
}
