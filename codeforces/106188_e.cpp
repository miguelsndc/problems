#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxn = 1e5 + 10;
ll val[mxn], sub_sum[mxn], sub_sqsum[mxn];
vector<int> g[mxn];
ll total, sumsq, bestLost;

void dfs1(int u, int p = -1) {
    sub_sum[u] = val[u];
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub_sum[u] += sub_sum[v];
    }
}

void dfs2(int u, int p = -1) {
    sub_sqsum[u] = val[u] * val[u];
    for (int v : g[u]) {
        if (v == p) continue;
        dfs2(v, u);
        sub_sqsum[u] += sub_sqsum[v];
    }
}

void dfs3(int u, int p = -1) {
    for (int v : g[u]) {
        if (v == p) continue;
        bestLost = max(bestLost, sub_sum[v] * (total - sub_sum[v]));
        dfs3(v, u);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);

    total = sub_sum[1];
    sumsq = sub_sqsum[1];

    dfs3(1);

    cout << ((total * total - sumsq) / 2 - bestLost);
}
