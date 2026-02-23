#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, q; cin >> n >> q;
    vector<int> a(n), qid(q), ans(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pii> queries(q);
    iota(qid.begin(), qid.end(), 0);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries[i] = {--l, r}; //[l, r)
    }
    const int inf = 1e9 + 8;
    auto solve = [&](auto &solve, int l, int r, vector<int> &qid) -> void {
        if (r - l == 1) {
            for (int i: qid) {
                auto [l, r] = queries[i];
                ans[i] = a[l];
            }
            return;
        }
        int m = (l + r) / 2;
        vector<int> pre(m - l + 1, inf), suf(r - m + 1, inf);
        for (int i = m - 1; i >= l; i--) pre[i - l] = min(pre[i + 1 - l], a[i]);
        for (int i = m + 1; i <= r; i++) suf[i - m] = min(suf[i - m - 1], a[i - 1]);
        vector<int> qid_l, qid_r;
        for (int i : qid) {
            auto [nl, nr] = queries[i];
            if (nr <= m) qid_l.push_back(i);
            else if (nl >= m) qid_r.push_back(i);
            else ans[i] = min(pre[nl - l], suf[nr - m]);
        }
        solve(solve, l, m, qid_l);
        solve(solve, m, r, qid_r);
    };
    solve(solve, 0, n, qid);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
