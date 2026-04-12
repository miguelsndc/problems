#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct BIT{
    int n;
    vector<ll> bit;
    BIT(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum [0..pos] (0-based)
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    auto at_most = [&] (ll x) -> ll {
        BIT bit(n + 1);
        ll inv = 0, ans = 0;
        int r = 0;
        for (int l = 0; l < n; l++) {
            if(r < l) r = l;
            while(r < n and inv + (bit.sum(n) - bit.sum(p[r])) <= x) {
                inv += bit.sum(n) - bit.sum(p[r]);
                bit.add(p[r], 1);
                r++;
            }
            ans += (r - l);
            bit.add(p[l], -1);
            inv -= bit.sum(p[l]);
        }
        return ans;
    };
    cout << at_most(k) - (k > 0 ? at_most(k - 1) : 0) << '\n';
}