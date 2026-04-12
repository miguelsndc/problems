#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
template<typename T>
struct BIT{
    int n;
    vector<T> bit;
    BIT(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, T val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum [0..pos] (0-based)
    T sum(int pos) const {
        if (pos < 0) return 0;
        T s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
const int ms = 5e5 + 10;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    BIT<long long> bitsum(ms+1), bitfreq(ms+1);
    for (auto x: a) {
        bitsum.add(x, x);
        bitfreq.add(x, 1);
    }
    while(q--){
        int type; cin>>type;
        if (type==1) {
            int x, y; cin >> x >> y; --x;
            bitsum.add(a[x], -a[x]);
            bitfreq.add(a[x], -1);
            bitsum.add(y, y);
            bitfreq.add(y, 1);
            a[x] = y;
        }else {
            int l, r; cin >> l >> r;
            long long sum_l = bitsum.sum(l), fr_l = bitfreq.sum(l), total = bitsum.sum(ms);
            long long sum_r = bitsum.sum(ms) - bitsum.sum(r - 1),
                      fr_r = bitfreq.sum(ms) - bitfreq.sum(r - 1);

            if (l < r) {
                total -= sum_l;
                total -= sum_r;
                total += 1ll * l * fr_l;
                total += 1ll * r * fr_r;
                cout << total << '\n';
            } else {
                cout << 1ll * l * bitfreq.sum(ms) << '\n';
            }
        }
    }
}