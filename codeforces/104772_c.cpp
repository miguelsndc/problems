#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
#include <bits/stdc++.h>
using namespace std;

/*
2-satisfiability testado em (https://judge.yosupo.jp/problem/two_sat)
N variáveis e M clausulas de (and, or, xor, nor,etc) para serem satisfeitas
ao mesmo tempo, determina se existe e dá uma resposta.
O(N + M) com Kosaraju
*/

struct two_sat {
    int n;
    vector<vector<int>> graph, reverse_graph;
    vector<int> components, topo_order, answer;
    vector<bool> visited;

    two_sat() {}
    two_sat(int _n) : n(_n) {
        graph.assign(2 * n, {});
        reverse_graph.assign(2 * n, {});
        components.assign(2 * n, 0);
        visited.assign(2 * n, false);
        answer.assign(n, 0);
    }

    inline int var(int i, bool val) {
        return 2 * i + (val ? 0 : 1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    void add_or(int i, bool f, int j, bool g) {
        add_edge(var(i, !f), var(j, g));
        add_edge(var(j, !g), var(i, f));
    }
    void add_implica(int i, bool f, int j, bool g) {
        add_or(i, !f, j, g);
    }
    // Ambos true
    void add_and(int i, bool f, int j, bool g) {
        add_edge(var(i, !f), var(i, f));
        add_edge(var(j, !g), var(j, g));
    }

    // Exatamente um deve ser true
    void add_xor(int i, bool f, int j, bool g) {
        add_or(i, f, j, g);
        add_or(i, !f, j, !g);
    }

    // Ambos falsos
    void add_nor(int i, bool f, int j, bool g) {
        add_edge(var(i, f), var(i, !f));
        add_edge(var(j, g), var(j, !g));
    }

    void dfs(int u) {
        visited[u] = true;
        for (int v : graph[u])
            if (!visited[v]) dfs(v);
        topo_order.push_back(u);
    }

    void scc(int u, int id) {
        visited[u] = true;
        components[u] = id;
        for (int v : reverse_graph[u])
            if (!visited[v]) scc(v, id);
    }

    bool satisfiable() {
        fill(visited.begin(), visited.end(), false);
        topo_order.clear();
        for (int i = 0; i < 2 * n; i++)
            if (!visited[i]) dfs(i);

        fill(visited.begin(), visited.end(), false);
        reverse(topo_order.begin(), topo_order.end());

        int id = 0;
        for (int v : topo_order)
            if (!visited[v]) scc(v, id++);

        for (int i = 0; i < n; i++) {
            if (components[var(i, 0)] == components[var(i, 1)])
                return false;
            answer[i] = components[var(i, 0)] < components[var(i, 1)];
        }
        return true;
    }
};
bool faz(int u, int n, int size, vector<vector<int>>& g, vector<vector<int>> &pares, vector<int>& cor, vector<int> &ans) {
    ans.clear();
    two_sat sat(size);
    for (auto &v: pares) {
        sat.add_xor(v[0], true, v[1], true);
    }
    sat.add_or(u, true, u, true);
    auto dfs = [&](auto&&self, int u, int p = -1) -> void {
        if (p != -1) {
            sat.add_implica(u, true, p, true);
        }
        for (int v: g[u]) {
            if (v != p) self(self, v, u);
        }
    };
    dfs(dfs, u, -1);
    int ok = sat.satisfiable();
    if (ok) {
        for (int i = 0; i < size; i++) {
            if (sat.answer[i]) ans.push_back(i + 1);
        }
    }
    return ok;
}
void dale() {
    int n;
    cin >> n;
    vector g(2 * n, vector<int>());
    vector<int> cor(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> cor[i], --cor[i];
    for (int i = 0; i < 2 * n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<vector<int>> pares(n);
    for (int i = 0; i < 2 * n; i++) {
        pares[cor[i]].push_back(i);
    }
    vector<int> ans;
    for (int x : pares[0]) {
        if(faz(x, n, 2 * n, g, pares, cor, ans)) {
            for (int x: ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}