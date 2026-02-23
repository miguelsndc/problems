#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {  // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        k *= -1, m *= -1;
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        ll bla = l.k * x + l.m;
        return -bla;
    }
};
const int mxn = 1e5 + 10;
vector<int> g[mxn];
vector<ll> dp(mxn), a(mxn), b(mxn);
LineContainer* dfs(int u, int p = -1) {
    bool folha = true;
    auto cur = new LineContainer();
    for (int v : g[u]) {
        if (v == p) continue;
        folha = false;
        auto child = dfs(v, u);
        if (cur->size() < child->size()) {
            swap(cur, child);
        }
        for (auto line : *child) {
            cur->add(-line.k, -line.m);
        }
        delete child;
    }
    if (folha && u != 1) {
        dp[u] = 0;
    } else {
        dp[u] = cur->query(a[u]);
    }

    if (u != 1) cur->add(b[u], dp[u]);
    return cur;
}
void dale() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}