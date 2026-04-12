#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
const int mxn = 1e5 + 10;
int n, l, r;
vector<int> adj[mxn];
int deleted[mxn], subtree_size[mxn], bit[mxn];
long long ans = 0, low = 0, high = 0;
void add(int i, int v) {
    if (i <= 0) return;
    for (; i <= n; i += i & -i) bit[i] += v;
}
int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) sum += bit[i];
    return sum;
}
int range(int l, int r) {
    if (l > r or l > n) return 0;
    r = min(r, n);
    return query(r) - query(l - 1);
}
void get_sz(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p and !deleted[v]) {
            get_sz(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}
int get_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p and !deleted[v] and subtree_size[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}
void pega_distancias(int u, int p, int dist, vector<int>& distancia) {
    distancia.push_back(dist);
    for (int v : adj[u]) {
        if (v != p and !deleted[v]) {
            pega_distancias(v, u, dist + 1, distancia);
        }
    }
}

void dale_centroid(int node) {
    get_sz(node, -1);
    int centroid = get_centroid(node, -1, subtree_size[node]);
    vector<int> distancias;
    for (int v : adj[centroid]) {
        if (deleted[v]) continue;
        vector<int> cur;
        pega_distancias(v, centroid, 1, cur);
        for (int d : cur) {
            // desse cara pro centroid
            if (d >= low and d <= high) {
                ans++;
            }
            int lb = max(1ll, low - d);
            int ub = high - d;
            if (lb <= ub) {
                ans += range(lb, ub);
            }   
        }
        for (int d : cur) {
            add(d, 1);
            distancias.push_back(d);
        }
    }
    for (int d : distancias) add(d, -1);
    deleted[centroid] = true;
    for (int v : adj[centroid]) {
        if (!deleted[v]) dale_centroid(v);
    }
}

void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deleted[i] = false;
        bit[i] = 0;
    }
    ans = 0;
    low = max(1, n - r - 1);
    high = n - l - 1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (high >= 1) {
        dale_centroid(1);
    }
    cout << ans<< '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("awesome.in", "r", stdin);
    int tt;
    cin >> tt;
    while (tt--) solve();
}
