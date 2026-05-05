#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
/*
    Kosaraju's algorithm
    Finds Strongly Connected Components (SCCs) in a directed graph in O(V + E)
    and builds the condensation graph (a DAG of the SCCs).
*/
#include <bits/stdc++.h>
using namespace std;

struct Kosaraju {
    int n;
    vector<vector<int>> adj, rev_adj;
    vector<bool> visited;
    vector<int> order;      

    vector<int> scc_id;           
    vector<vector<int>> scc_nodes;// Lists of original nodes grouped by their SCC ID
    vector<vector<int>> cond_adj; // Adjacency list for the condensation graph (DAG)

    Kosaraju(int n) : n(n), adj(n), rev_adj(n), scc_id(n) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    void dfs1(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) dfs1(u);
        }
        order.push_back(v);
    }
    void dfs2(int v, int id, vector<int>& current_scc) {
        visited[v] = true;
        scc_id[v] = id;
        current_scc.push_back(v);
        for (int u : rev_adj[v]) {
            if (!visited[u]) dfs2(u, id, current_scc);
        }
    }
    void build() {
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs1(i);
        }
        visited.assign(n, false);
        reverse(order.begin(), order.end());

        int num_sccs = 0;
        for (int v : order) {
            if (!visited[v]) {
                vector<int> current_scc;
                dfs2(v, num_sccs++, current_scc);
                scc_nodes.push_back(current_scc);
            }
        }

        cond_adj.assign(num_sccs, vector<int>());
        for (int v = 0; v < n; v++) {
            for (int u : adj[v]) {
                int root_v = scc_id[v];
                int root_u = scc_id[u];
                if (root_v != root_u) {
                    cond_adj[root_v].push_back(root_u);
                }
            }
        }

        for (int i = 0; i < num_sccs; i++) {
            sort(cond_adj[i].begin(), cond_adj[i].end());
            cond_adj[i].erase(unique(cond_adj[i].begin(), cond_adj[i].end()), cond_adj[i].end());
        }
    }
};

const int ms = 5e4 + 5;
bitset<ms> reach[ms];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    Kosaraju ko(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ko.add_edge(--u, --v);
    }
    ko.build();
    auto cond = ko.cond_adj;
    vector<int> vis(n), order;
    auto dfs = [&] (auto &&self, int u) -> void {
        vis[u] = true;
        for (int v: cond[u]) {
            if (!vis[v]) self(self, v);
        }
        order.push_back(u);
    };
    for (int i = 0; i < cond.size(); i++) {
        if (!vis[i]) dfs(dfs, i);
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < n; i++) {
        reach[ko.scc_id[i]].set(ko.scc_id[i], 1);
    }
    for (int i = 0; i < order.size(); i++) {
        int u = order[i];
        for (int v : cond[u]) {
            reach[v] |= reach[u];
        }
    }
    while(q--) {
        int a, b; cin >> a >> b;
        if (ko.scc_id[--a] == ko.scc_id[--b]) {
            cout << "YES\n";
            continue;
        }
        if (reach[ko.scc_id[b]].test(ko.scc_id[a])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}