#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) {
        par.assign(n, 0);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
        sz[x_root] += sz[y_root];
        par[y_root] = x_root;
        return true;  
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> a(n), pre(n), suf(n);
    for (int& i : a) cin >> i;
    suf[n - 1] = a[n - 1], pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    int ming = pre[n - 1];
    UnionFind dsu(n);
    ll cost = 0, left = 0, right = n - 1;
    for (int i = 1; i < n; i++) {
        if (pre[i] == ming) {
            if (dsu.unite(left, i)) {
                cost += pre[i];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (suf[i] == ming) {
            if (dsu.unite(right, i)) {
                cost += suf[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) != dsu.find(left) and dsu.unite(left, i)) {
            cost += min(pre[i], suf[i]);
        }
    }

    cout << cost << '\n';
}