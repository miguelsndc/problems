#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int ms = 1e5 + 5;
int prof[ms], sz[ms], bit[ms + 1], ans[ms];
int query(int p) {
    int sum = 0;
    for (int i = p; i > 0; i -= i & -i) sum += bit[i];
    return sum;
}
void update(int pos, int val) {
    for (int i = pos; i < ms; i += i & -i) bit[i] += val;
}
vector<int> tree[ms];
void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v: tree[u]) {
        if (v == p) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}
void add(int u, int val) {
    if (val == 1) {
        update(prof[u], 1);
    } else {
        update(prof[u], -1);
    }
}
void put(int u, int p, int val) {
    add(u, val);
    for (int v: tree[u]) {
        if (v == p) continue;
        put(v, u, val);
    }
}
void sack (int u, int p, int keep) {
    int big = -1;
    for (int v: tree[u]) {
        if (v == p) continue;
        if (big == -1 or sz[v] > sz[big]) {
            big = v;
        }
    }
    for (int v: tree[u]) {
        if (v == p or v == big) continue;
        sack(v, u, 0);
    }
    if (big != -1) sack(big, u, 1);
    add(u, 1);
    for (int v : tree[u]) {
        if (v == p or v == big) continue;
        put(v, u, 1);
    }   
    ans[u] = query(ms) - query(prof[u]);
    if (!keep) {
        put(u, p, -1);
    }
}
void slve() {
    int n; cin >> n;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> prof[i];
        b.push_back(prof[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto get = [&] (int x) {
        return int(lower_bound(b.begin(), b.end(), x) - b.begin()) + 1;
    };
    for (int i = 1; i <= n; i++) prof[i] = get(prof[i]);
    for (int i = 2; i <= n; i++) {
        int par; cin >> par;
        tree[par].push_back(i);
        tree[i].push_back(par);
    }
    dfs_size(1,0);
    sack(1,0,0);
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;//  cin >> tt;
    while(tt--) slve();
}