#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int BLOCK = 400, mx = 2e5 + 10;
vector<int> a(mx), freq(mx);
struct query {
    int l, r, id;
    bool operator<(const query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < o.r) : (r > o.r);
    }
};
int distinct = 0;
void add(int i) {
    if (freq[a[i]]++ == 0) {
        distinct++;
    }
}
void remove(int i) {
    if (--freq[a[i]] == 0) {
        distinct--;
    }
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
        ans[q.id] = distinct;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.push_back(a[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    }
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