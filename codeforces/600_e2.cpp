#include <bits/stdc++.h>
using namespace std;

// #define sz(x) ((int)(x).size())
#define ll long long
const int ms = 1e5 + 5;
#define pii pair<int, int>
int color[ms], sz[ms]; int freq[ms], seen[ms];
ll ans[ms], sum[ms];
multiset<int> s;
vector<int> tree[ms];
void dfs_size(int u, int p = -1) {
    sz[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}
/*
    -> qual a frequencia desse cara
    -> qual a soma dos caras q tem frequencia x
*/
void add(int u, int val = 1) {
    if (val == 1) {
        s.erase(s.find(freq[color[u]]));
        sum[freq[color[u]]] -= color[u];
        freq[color[u]]++;
        sum[freq[color[u]]] += color[u];
        s.insert(freq[color[u]]);
    } else {
        s.erase(s.find(freq[color[u]]));
        sum[freq[color[u]]] -= color[u];
        freq[color[u]]--;
        sum[freq[color[u]]] += color[u];
        s.insert(freq[color[u]]);
    }
}
void put(int u, int val, int p) {
    add(u, val);
    for (int v: tree[u]) {
        if (v == p) continue;
        put(v, val, u);
    }   
}
void sack(int u, int p = -1, bool keep = 0) {
    int big = -1;
    for (int v : tree[u]) {
        if (v == p) continue;
        if (big == -1 or sz[v] > sz[big]) {
            big = v;
        }
    }
    for (int v : tree[u]) {
        if (v == p or v == big) continue;
        sack(v, u, 0);
    }
    if (big != -1) sack(big, u, true);
    add(u);
    for (int v: tree[u]) {
        if (v == p or v == big) continue;
        put(v, 1, u);
    }
    ans[u] = sum[*s.rbegin()];
    if (!keep) {
        put(u, -1, p);
    }
}
void slve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        if (!seen[color[i]]) {
            s.insert(0);
            sum[0] += color[i];
            seen[color[i]] = true;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs_size(1);
    sack(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;// cin >> tt;
    while (tt--) slve();
}