#include <bits/stdc++.h>
using namespace std;
#define ssz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>
const int ms = 2e5 + 10;
int sz[ms], ans[ms], cnt[ms], color[ms], keep[ms], big[ms];
vector<int> g[ms];
void subsz(int u, int p) {
    sz[u] = 1;
    int mxsub = 0;
    for (int v : g[u]) {
        if (v != p) {
            subsz(v, u);
            sz[u] += sz[v];
            if (sz[v] > mxsub) {
                mxsub = sz[v];
                big[u] = v;
            }
        }
    }
}
int distinct = 0;
void add(int u, int p, int val) {
    if (cnt[color[u]] == 0 and val == 1) distinct++;
    if (cnt[color[u]] == 1 and val == -1) distinct--;
    cnt[color[u]] += val;
    for (int v: g[u]) {
        if (v != p and !keep[v]) {
            add(v, u, val);
        }
    }
}
void dfs(int u, int p, bool keep_node) {
    for (int v: g[u]) {
        if (v != p and v != big[u]) {
            dfs(v, u, 0);
        }
    }
    if (big[u]) {
        dfs(big[u], u, 1);
        keep[big[u]] = true;
    }
    add(u, p, 1);
    ans[u] = distinct;
    if (big[u]) keep[big[u]] = 0;
    if (!keep_node) add(u, p, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> colors;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        colors.push_back(color[i]);
    }
    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());
    for (int i = 1; i <= n; i++) {
        color[i] = lower_bound(colors.begin(), colors.end(), color[i]) - colors.begin();
    }
    for (int i = 1; i + 1 <= n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    subsz(1, 0);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}