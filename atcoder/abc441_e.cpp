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
    void add(int pos, int val = 1) {
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a[i] = 1;
        if (s[i] == 'B') a[i] = -1;
        if (s[i] == 'C') a[i] = 0;
    }
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];

    vector<int> b = ps;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto get = [&] (int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };
    BIT<int> bit(n + 5);
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        int v = get(ps[i]) - 1;
        bit.add(get(ps[i]), 1);
        ans += bit.sum(v);
    }
    cout << ans;
}