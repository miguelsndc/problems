#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 1e6 + 5;
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
    int n, m; cin >> n >> m;
    vector<ii> segs(n);
    for (auto &[x, y]: segs) cin >> x >> y;
    struct evento {
        int r, tipo, l, id;
        bool operator<(const evento &other) {
            if (other.r == r) return tipo < other.tipo;
            return r < other.r;
        }
    };
    vector<evento> v;
    vector<int> ans(m);
    for (auto &[x, y]: segs) {
        v.push_back({y, 0, x, -1});
    }
    Fenwick ft(ms);
    for(int id = 0; id < m; id++) {
        int cnt; cin >> cnt;
        vector<int> pts(cnt + 2);
        pts[0] = 0;
        for (int i = 1; i <= cnt; i++) cin >> pts[i];
        pts[cnt + 1] = ms;
        vector<ii> intervals;
        for (int i = 0; i + 1 < (int)pts.size(); i++) {
            if (pts[i] + 1 <= pts[i + 1] - 1) intervals.push_back({pts[i] + 1, pts[i + 1] - 1});
        }
        for (auto &[l, r]: intervals) v.push_back({r, 1, l, id});
    }
    sort(v.begin(), v.end());
    for (auto &[r, tipo, l, id]: v) {
        if (tipo) {
            ans[id] += ft.sum(ms) - ft.sum(l - 1);
        } else {
            ft.add(l, 1);
        }
    }
    for (int x: ans) cout << n - x << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}