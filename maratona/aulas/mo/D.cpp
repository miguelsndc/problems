#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int BLOCK = 500, mx = 2e5 + 10;
int a[mx], freq[mx], cur_min = 1e9;
vector<int> values;
map<int, int> rev;
struct query {
    int l, r, id;
    bool operator<(const query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < o.r) : (r > o.r);
    }
};
void add(int i) {
    freq[a[i]]++;
    cur_min = min(cur_min, a[i]);
}
void remove(int i) { 
    freq[a[i]]--;
    if (a[i] == cur_min and freq[a[i]] == 0) {
        while(cur_min < mx and freq[cur_min] == 0) {
            cur_min++;
        }
    }
}

void mo(vector<query>& queries, vector<int>& ans) {
    assert(sz(ans) == sz(queries));
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto& q : queries) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        ans[q.id] = rev[cur_min];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i], values.push_back(a[i]);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < n; i++) {
        int b = int(lower_bound(values.begin(), values.end(), a[i]) - values.begin());
        rev[b] = a[i]; 
        a[i] = b;
    }
    vector<query> queries(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[i] = {l, r, i};
    }
    mo(queries, ans);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}