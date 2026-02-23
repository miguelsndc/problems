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
        ll bla =  l.k * x + l.m;
        return -bla;
    }
};
void dale() {
    int n;
    cin >> n;
    ll C;
    cin >> C;
    vector<ll> h(n);
    for (ll& i : h) cin >> i;
    vector<ll> dp(n);
    LineContainer lc;
    dp[0] = 0;
    /*
        min(C + (hi - hj)²)
        C + min((hi - hj)²)
        C + min(hi² - 2hihj + hj²)
        C + hi² + min(-2hihj + hj²)
        C + hi² + f_y(x) onde f(x) = -2xhj + hj²
    */
    lc.add(-2*h[0], h[0]*h[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = C + h[i] * h[i] + lc.query(h[i]);
        lc.add(-2*h[i], dp[i] + h[i] * h[i]);
    }

    cout << dp[n - 1] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}