#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int BLOCK = 400, mx = 2e5 + 10;
int freq[mx], tin[mx], tout[mx], et[mx], color[mx], timer = 0;
vector<int> g[mx];
void euler(int u, int p) {
    tin[u] = ++timer;
    et[timer] = color[u];
    for (int v: g[u]) {
        if (v != p) euler(v, u);
    }
    tout[u] = timer;
}
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
    if (freq[et[i]]++ == 0) distinct++;
}
void remove(int i) {
    if (freq[et[i]]-- == 1) distinct--;
}
void mo(vector< query> &queries, vector<int> &ans) {
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
    vector<int> b;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        b.push_back(color[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        color[i] = int(lower_bound(b.begin(), b.end(), color[i]) - b.begin());
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    euler(0, -1);
    vector<query> queries(n); vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        queries[i] = {tin[i], tout[i], i};
    }
    mo(queries, ans);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}