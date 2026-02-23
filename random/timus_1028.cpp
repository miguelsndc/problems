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
void dale() {
    int n; cin >> n;
    vector<int> ans(n);
    vector<pii> points(n);
    for (pii &p: points) cin >> p.first >> p.second;
    Fenwick ft((int)1e6);
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) {
        int x = ft.sum(points[i].second);
        ans[x]++;
        ft.add(points[i].second, 1);
    }
    for (int x: ans) {
        cout <<x << '\n';
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}