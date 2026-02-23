#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
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
    int n, d;
    cin >> n >> d;
    vector<int> t(n), pos, neg;
    for (int& i : t) cin >> i;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+')
            pos.push_back(t[i]);
        else
            neg.push_back(t[i]);
    }
    vector<int> b = t;
    for (int x : t) {
        b.push_back(x - d - 1);
        b.push_back(x - d);
        b.push_back(x - 1);
        b.push_back(x + d);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    auto get = [&](int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };

    Fenwick bit(sz(b));
    for (int x : neg) {
        bit.add(get(x), 1);
    }

    ll ans = 0;
    for (int x : pos) {
        ll agora = bit.sum(get(x + d)) - bit.sum(get(x));
        agora += bit.sum(get(x - 1)) - bit.sum(get(x - d - 1));
        ans += agora;
    }

    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}