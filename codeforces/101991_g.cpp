#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

struct query_data {
    int l, r, d, id;
};

struct range_gcd {
    int g, l, r;
};

const int MAX_A = 100005;
const int MAX_Q = 50005;
long long ans[MAX_Q];
int a[MAX_A];

void solve(int l, int r, vector<query_data>& queries) {
    if (queries.empty()) return;

    if (l == r) {
        for (auto& q : queries) {
            if (a[l] == q.d) ans[q.id]++;
        }
        return;
    }

    int m = l + (r - l) / 2;
    vector<query_data> q_left, q_right, q_cross;

    for (auto& q : queries) {
        if (q.r <= m) {
            q_left.push_back(q);
        } else if (q.l > m) {
            q_right.push_back(q);
        } else {
            q_cross.push_back(q);
            q_left.push_back({q.l, m, q.d, q.id});
            q_right.push_back({m + 1, q.r, q.d, q.id});
        }
    }

    if (!q_cross.empty()) {
        vector<range_gcd> left_blocks, right_blocks;

        int curr_g = a[m], last = m;
        for (int i = m - 1; i >= l; --i) {
            int nxt_g = __gcd(curr_g, a[i]);
            if (nxt_g != curr_g) {
                left_blocks.push_back({curr_g, i + 1, last});
                curr_g = nxt_g;
                last = i;
            }
        }
        left_blocks.push_back({curr_g, l, last});

        curr_g = a[m + 1];
        last = m + 1;
        for (int i = m + 2; i <= r; ++i) {
            int nxt_g = __gcd(curr_g, a[i]);
            if (nxt_g != curr_g) {
                right_blocks.push_back({curr_g, last, i - 1});
                curr_g = nxt_g;
                last = i;
            }
        }
        right_blocks.push_back({curr_g, last, r});

        for (auto& q : q_cross) {
            map<int, long long> a_suf, b_pref;

            for (auto& b : left_blocks) {
                int start = max(q.l, b.l);
                int end = b.r;
                if (start <= end) a_suf[b.g] += (end - start + 1);
            }

            for (auto& b : right_blocks) {
                int start = b.l;
                int end = min(q.r, b.r);
                if (start <= end) b_pref[b.g] += (end - start + 1);
            }

            for (auto [g1, cnt1] : a_suf) {
                for (auto [g2, cnt2] : b_pref) {
                    if (__gcd(g1, g2) == q.d) {
                        ans[q.id] += (1ll) * cnt1 * cnt2;
                    }
                }
            }
        }
    }

    solve(l, m, q_left);
    solve(m + 1, r, q_right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<query_data> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].l >> queries[i].r >> queries[i].d;
            queries[i].id = i;
            ans[i] = 0;
        }

        solve(1, n, queries);

        for (int i = 0; i < q; ++i) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}