#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()
const int ms = 3e5 + 10, mod = 1e9 + 7;

struct node {
    int mx = 0;
    ll cnt = 0;
};
void add(ll &x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}
node tree[ms]; 
node join(const node& a, const node& b) {
    if (a.mx > b.mx) return a;
    else if (a.mx < b.mx) return b;
    ll k = 0;
    add(k, a.cnt + b.cnt);
    return {a.mx, k};
}
void update(int pos, int val, ll amount, int max_idx) {
    for (; pos <= max_idx; pos += pos & -pos) {
        if (tree[pos].mx == val) {
            add(tree[pos].cnt, amount);
        } else if (val > tree[pos].mx) {
            tree[pos].mx = val;
            tree[pos].cnt = amount;
        }
    }
}
node query(int pos) {
    node res = {0, 0};
    for (; pos > 0; pos -= pos & -pos) {
        res = join(res, tree[pos]);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (auto& x : a) {
        cin >> x;
        b.push_back(x);
        b.push_back(x - 1);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    auto get = [&](int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };
    
    vector<ll> d(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) {
        node x = query(get(a[i - 1] - 1)); 
        ll ways = x.cnt;
        if (x.mx == 0) ways = 1;
        d[i] = x.mx + 1;
        update(get(a[i - 1]), d[i], ways, sz(b));
    }
    
    node res = query(sz(b));
    cout << res.mx << ' ' << res.cnt  << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}