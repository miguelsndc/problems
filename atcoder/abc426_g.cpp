#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxw = 511;
void dale() {
    int n; cin >> n;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    int q; cin >> q;
    vector<tuple<int, int, int>> queries(q);
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r, c; cin >> l >> r >> c;
        queries[i] = {--l, r, c};
    }
    // o(maxw)
    auto update_dp =[&](vector<ll> &dp_prev, vector<ll> &dp_next, int i) {
        for (int j = 0; j < maxw; j++) {
            dp_next[j] = dp_prev[j];
            if (j >= w[i]) {
                dp_next[j] = max(dp_next[j], dp_prev[j - w[i]] + v[i]);
            }
        }
    };
    vector dp(n + 1, vector<ll>(maxw));
    auto solve = [&] (auto &solve, int l, int r, vector<int> &qid) -> void {
        if (l + 1 == r) {
            for (int i: qid) {
                auto [nl, nr, nc] = queries[i];
                ans[i] = (nc >= w[nl] ? v[nl] : 0);
            }
            return;
        }
        int m = (l + r) / 2;
        fill(dp[m].begin(), dp[m].end(), 0);
        for (int i = m - 1; i >= l; i--) update_dp(dp[i + 1], dp[i], i);
        for (int i = m + 1; i <= r; i++) update_dp(dp[i - 1], dp[i], i - 1);
        vector<int> qid_l, qid_r;
        for (int i: qid) {
            auto [nl, nr, nc] = queries[i];
            if (nr <= m) qid_l.push_back(i);
            else if (nl >= m) qid_r.push_back(i);
            else for (int j = 0; j <= nc; j++) {
                ans[i] = max(ans[i], dp[nl][j] + dp[nr][nc - j]); 
            }
        }
        if (qid_l.size()) solve(solve, l, m, qid_l);
        if (qid_r.size()) solve(solve, m, r, qid_r);
    };
    vector<int> qid(q);
    iota(qid.begin(), qid.end(), 0);
    solve(solve, 0, n, qid);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}