#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int v, vector<vector<int>>& adj, vector<int>& output) {
    visited[v] = true;
    for (int u : adj[v])
        if (!visited[u]) dfs(u, adj, output);
    output.push_back(v);
}

vector<vector<int>> scc(vector<vector<int>>& adj,
                        vector<vector<int>>& adj_transp,
                        vector<int>& root) {
    int n = adj.size();
    vector<vector<int>> components;
    vector<int> order;

    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i, adj, order);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    for (int v : order) {
        if (!visited[v]) {
            vector<int> comp;
            dfs(v, adj_transp, comp);
            for (int u : comp) root[u] = components.size();
            components.push_back(comp);
        }
    }
    return components;
}

void dale() {
    int c, b;
    cin >> c >> b;
    vector<vector<int>> g(c), gt(c), cond;
    for (int i = 0; i < b; i++) {
        int li, mi;
        cin >> li >> mi;
        li--;
        for (int j = 0; j < mi; j++) {
            int ai;
            cin >> ai;
            ai--;
            g[li].push_back(ai);
            gt[ai].push_back(li);
        }
    }
    vector<int> root(c);
    auto comps = scc(g, gt, root);
    int n_scc = comps.size();
    vector<int> in(n_scc, 0);
    for (int u = 0; u < c; u++) {
        for (int v : g[u]) {
            if (root[u] != root[v]) in[root[v]]++;
        }
    }
    int src = -1, cnt = 0;
    for (int i = 0; i < n_scc; i++) {
        if (in[i] == 0) {
            cnt++;
            src = i;
        }
    }
    if (cnt == 1) {
        cout << comps[src].size() << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dale();
}