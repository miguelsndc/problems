#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int ms = 1e5 + 10, BLOCK = 316; 
ll bit[ms + 10], ans[ms], a[ms], inv = 0;

void update(int pos, int val = 1) {
    for (int i = pos + 1; i < ms; i += i & -i) bit[i] += val;
}
ll sum(int pos) {
    if (pos < 0) return 0;
    ll s = 0;
    for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
    return s;
}

struct Query {
    int l, r, id;
    bool operator<(const Query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < o.r) : (r > o.r);
    }
};

void add_left(int i) {
    inv += sum(a[i] - 1);
    update(a[i], 1);
}
void add_right(int i) {
    inv += sum(ms) - sum(a[i]);
    update(a[i], 1);
}
void remove_left(int i) {
    update(a[i], -1); 
    inv -= sum(a[i] - 1); 
}
v   oid remove_right(int i) {
    update(a[i], -1);
    inv -= sum(ms) - sum(a[i]); 
}

void mo(vector<Query>& queries) {
    sort(queries.begin(), queries.end());

    int L = 0, R = -1;
    for (auto& q : queries) {
        while (L > q.l) add_left(--L);
        while (R < q.r) add_right(++R);
        while (L < q.l) remove_left(L++);
        while (R > q.r) remove_right(R--);
        ans[q.id] = inv;
    }
}

void slve() {
    int n, q; cin >> n >> q;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].r--; 
        queries[i].id = i;
    }
    
    mo(queries);
    
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; 
    while (tt--) slve();
}