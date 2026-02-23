#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

void dale() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    struct Query {
        int pos, val, coef, id;
        bool operator<(const Query& other) const { // adicionar const
            return pos < other.pos;
        }
    };

    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        queries.push_back({B, D, 1, i});
        queries.push_back({B, C - 1, -1, i});
        queries.push_back({A - 1, D, -1, i});
        queries.push_back({A - 1, C - 1, 1, i});
    }

    vector<int> vals = a;
    for (const auto &q : queries) vals.push_back(q.val);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto get = [&](int x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };

    for (auto &q : queries) q.val = get(q.val);
    for (int &x : a) x = get(x);

    sort(queries.begin(), queries.end());

    Fenwick bit(vals.size() + 10);
    vector<ll> ans(q);

    int j = 0;
    while (j < (int)queries.size() && queries[j].pos == 0) {
        ans[queries[j].id] += queries[j].coef * bit.sum(queries[j].val);
        j++;
    }

    for (int i = 0; i < n; i++) {
        bit.add(a[i], 1);
        while (j < (int)queries.size() && queries[j].pos == i + 1) {
            ans[queries[j].id] += queries[j].coef * bit.sum(queries[j].val);
            j++;
        }
    }

    for (auto x : ans) cout << x << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}
