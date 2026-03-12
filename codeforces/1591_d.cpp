#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

struct BIT{
    int n;
    vector<i64> bit;
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
    i64 sum(int pos) const {
        if (pos < 0) return 0;
        i64 s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> freq;
    bool done = false;
    BIT bit(n + 1);
    for (auto &x: a) {
        cin >> x;
        freq[x]++;
        if (freq[x] >= 2) { 
            done = true;
        }
    }
    i64 inv = 0;
    for (int i = n - 1; i >= 0; i--) {
        inv += bit.sum(a[i] - 1);
        bit.add(a[i], 1);
    }
    done |= (inv % 2 == 0);

    if (done) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
