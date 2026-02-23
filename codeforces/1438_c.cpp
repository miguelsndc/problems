#include <bits/stdc++.h>
using namespace std;
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
void dale() {
    int n, m;
    cin >> n >> m;
    vector mat(n, vector<int>(m));
    for (auto& v : mat)
        for (int& i : v) cin >> i;
    auto id = [&](int i, int j) {
        return i * m + j;
    };
    two_sat solver(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                if (mat[i][j] == mat[i + 1][j]) {
                    solver.add_xor(id(i, j), true, id(i + 1, j), true);
                } else if (mat[i][j] + 1 == mat[i + 1][j]) {
                    solver.add_implica(id(i, j), true, id(i + 1, j), true);
                }
            }
            if (i - 1 >= 0) {
                if (mat[i][j] == mat[i - 1][j]) {
                    solver.add_xor(id(i, j), true, id(i - 1, j), true);
                } else if (mat[i][j] + 1 == mat[i - 1][j]) {
                    solver.add_implica(id(i, j), true, id(i - 1, j), true);
                }
            }
            if (j - 1 >= 0) {
                if (mat[i][j] == mat[i][j - 1]) {
                    solver.add_xor(id(i, j), true, id(i, j - 1), true);
                } else if (mat[i][j] + 1 == mat[i][j - 1]) {
                    solver.add_implica(id(i, j), true, id(i, j - 1), true);
                }
            }
            if (j + 1 < m) {
                if (mat[i][j] == mat[i][j + 1]) {
                    solver.add_xor(id(i, j), true, id(i, j + 1), true);
                } else if (mat[i][j] + 1 == mat[i][j + 1]) {
                    solver.add_implica(id(i, j), true, id(i, j + 1), true);
                }
            }
        }
    }
    assert(solver.satisfiable());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] + solver.answer[id(i, j)] << " \n"[j == m - 1];
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}