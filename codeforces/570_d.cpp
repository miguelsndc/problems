#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
const int ms = 5e5 + 5;
int freq[26][ms], sz[ms], ans[ms], depth[ms]; char letter[ms];
vector<pii> queries[ms];
vector<int> g[ms];
void dfs_sz(int u, int p = -1, int d = 1) {
    sz[u] = 1;
    depth[u] = d;
    for (int v : g[u]) if (v != p) {
        dfs_sz(v, u, d + 1);
        sz[u] += sz[v];
    }
}
void add(int u, int val) {
    freq[(int)(letter[u] - 'a')][depth[u]] += val;
}
void put(int u, int p, int val) {
    add(u, val);
    for (int v : g[u]) if (v != p) {
        put(v, u, val);
    }
}
void sack(int u, int p = -1, int keep = 0) {
    int big = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        if (big == -1 or sz[v] > sz[big]) {
            big = v;
        }
    }
    for (int v : g[u]) {
        if (v == p or v == big) continue;
        sack(v, u, 0);
    }
    if (big != -1) sack(big, u, 1);
    add(u, 1);
    for (int v : g[u]) {
        if (v == p or v == big) continue;
        put(v, u, 1);
    }
    for (auto [id, d] : queries[u]) {
        int cntimpar = 0, cntpar = 0;
        for (int c = 0; c < 26; c++) {
            if (freq[c][d] > 0) {
                cntimpar += freq[c][d] & 1;
                cntpar += freq[c][d] % 2 == 0;
            }
        }
        if (cntimpar <= 1) {
            ans[id] = true;
        }
    }
    if (!keep) {
        put(u, p, -1);
    }
}
void slve() {
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int par; cin >> par;
        g[par].push_back(i);
        g[i].push_back(par);
    }
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        letter[i] = s[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int v, depth; cin >> v >> depth;
        queries[v].push_back({ i, depth });
    }
    dfs_sz(1);
    sack(1);
    for (int i = 0; i < m; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}