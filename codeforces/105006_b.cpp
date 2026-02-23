#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    string sep = "";
    for (const auto &x : v) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &a) {
    os << "{";
    string sep = "";
    for (const auto &x : a) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    string sep = "";
    for (const auto &x : s) os << sep << x, sep = ", ";
    return os << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
    os << "{";
    string sep = "";
    for (const auto &x : m) os << sep << "(" << x.first << ": " << x.second << ")", sep = ", ";
    return os << "}";
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << " " << H;
    dbg_out(T...);
}

#ifdef MIGUEL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int maxn = 1e5 + 5, mod = 1e9 + 7;
vector<vector<int>> tree(maxn);
vector<ll> sz(maxn), pw(maxn), ps(maxn);

int get_sz(int u, int p = -1) {
    sz[u] = 1;
    for (int v : tree[u]) {
        if (v != p) {
            sz[u] += get_sz(v, u);
        }
    }
    return sz[u];
}

void precalc() {
    pw[0] = 1;
    for (ll i = 1; i < maxn; i++) {
        pw[i] = 3 * pw[i - 1] % mod;
    }
    ps[0] = pw[0];
    for (int i = 1; i < maxn; i++)
        (ps[i] += (ps[i - 1] + pw[i]) % mod) %= mod;
}

void solve() {
    precalc();
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    get_sz(1, 0);
    ll ans = 0;
    dbg(ps);
    for (int v: tree[1]) {
        ans += ps[sz[v] - 1] % mod;
        ans %= mod;
    }
    cout << ans % mod<< '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin>>T;
    while (T--) solve();
}