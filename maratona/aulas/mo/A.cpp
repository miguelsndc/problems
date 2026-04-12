#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int BLOCK = 400, mx = 2e5 + 10;
vector<int> a(mx);
struct query {
    int l, r, id;
    bool operator<(const query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < o.r) : (r > o.r);
    }
};
long long sum = 0;
void add(int i) {
    sum += a[i];
}
void remove(int i) {
    sum -= a[i];
}
void mo(vector< query> &queries, vector<long long> &ans) {
    assert(sz(ans) == sz(queries));
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto &q: queries) {
        while(l > q.l) add(--l);
        while(r < q.r) add(++r);
        while(l < q.l) remove(l++);
        while(r > q.r) remove(r--);
        ans[q.id] = sum;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<query> queries(q);
    vector<long long> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; --l, --r;
        queries[i] = {l, r, i};
    }
    mo(queries, ans);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}