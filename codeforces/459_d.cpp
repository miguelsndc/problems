#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    Fenwick Tree - Range Queries
*/
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int,int> mp;
    vector<int> pre(n + 1), suf(n);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = mp[a[i]];
        mp[a[i]]++;
    }
    mp.clear();
    for (int i = 0; i < n; i++) {
        pre[i] = mp[a[i]];
        mp[a[i]]++;
    }
    Fenwick ft(n + 10);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += ft.sum(pre[i] - 1);
        ft.add(suf[i], 1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
