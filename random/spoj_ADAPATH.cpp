#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
 * Dinic's Algorithm - Maximum Flow / Minimum Cut
 * ---------------------------------------------------------------------
 * Complexidade:
 * - Geral: O(V^2 * E)
 * - Capacidades Unitárias: O(min(V^(2/3), E^(1/2)) * E)
 * - Bipartite Matching: O(E * sqrt(V))
 * ---------------------------------------------------------------------
 * Aplicações & Definições:
 * * 1. Min Cut (Corte Mínimo):
 * - O que é: O menor custo total de arestas para desconectar S de T.
 * - Como achar: Arestas que vão de u (Reachable) para v (!Reachable).
 * * 2. Max Bipartite Matching (Emparelhamento Máximo):
 * - O que é: Maior número de pares (u, v) possíveis entre dois grupos distintos.
 * - Montagem: S->L, R->T, L->R (todas caps=1). Flow = Tamanho do Matching.
 * * 3. Min Vertex Cover (Cobertura Mínima de Vértices - Bipartido):
 * - O que é: Menor conj. de vértices que "toca" todas as arestas do grafo.
 * - Recuperação: (L \ Reachable) U (R ∩ Reachable).
 * * 4. Max Independent Set (Conj. Independente Máximo - Bipartido):
 * - O que é: Maior conj. de vértices onde nenhum par de vértices é vizinho.
 * - Recuperação: Vértices Totais - Min Vertex Cover.
 * * 5. Max Weight Closure (Project Selection):
 * - O que é: Escolher nós (projetos) para maximizar lucro, respeitando dependências (custos).
 * - Montagem: S->Projeto(Lucro), Maquina->T(Custo), Dependência A->B (cap=INF).
 * - Resposta: Soma(Lucros Positivos) - MaxFlow.
 * * 6. Edge Disjoint Paths (Caminhos Aresta-Disjuntos):
 * - O que é: Max caminhos de S a T sem repetir arestas.
 * - Montagem: Capacidade de todas as arestas = 1.
 * * 7. Vertex Disjoint Paths (Caminhos Vértice-Disjuntos):
 * - O que é: Max caminhos de S a T sem repetir vértices.
 * - Montagem: Split node u -> (u_in -> u_out) com cap=1.
 * * 8. Min Path Cover (Cobertura de Caminhos em DAG):
 * - O que é: Mínimo de caminhos para visitar todos os nós de um DAG.
 * - Fórmula: Vértices - Max Bipartite Matching (do grafo de alcançabilidade).
 */
struct Dinic {
    struct Edge {
        int to, rev;
        ll cap;
    };
    vector<vector<Edge>> adj;
    vector<int> lvl, ptr, q;
    int n;

    Dinic(int n)
        : n(n)
        , adj(n)
        , lvl(n)
        , ptr(n)
        , q(n)
    {
    }

    void add_edge(int u, int v, ll cap)
    {
        adj[u].push_back({ v, (int)adj[v].size(), cap });
        adj[v].push_back({ u, (int)adj[u].size() - 1, 0 });
    }

    bool bfs(int s, int t)
    {
        fill(lvl.begin(), lvl.end(), -1);
        lvl[s] = 0;
        int head = 0, tail = 0;
        q[tail++] = s;
        while (head < tail) {
            int u = q[head++];
            for (auto& e : adj[u]) {
                if (e.cap > 0 && lvl[e.to] == -1) {
                    lvl[e.to] = lvl[u] + 1;
                    q[tail++] = e.to;
                }
            }
        }
        return lvl[t] != -1;
    }

    ll dfs(int u, int t, ll pushed)
    {
        if (pushed == 0 || u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < adj[u].size(); ++cid) {
            auto& e = adj[u][cid];
            if (lvl[u] + 1 != lvl[e.to] || e.cap == 0)
                continue;
            ll tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0)
                continue;
            e.cap -= tr;
            adj[e.to][e.rev].cap += tr;
            return tr;
        }
        return 0;
    }

    ll flow(int s, int t)
    {
        ll f = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, t, 1e18)) {
                f += pushed;
            }
        }
        return f;
    }

    vector<bool> get_reachable(int s)
    {
        vector<bool> vis(n);
        int head = 0, tail = 0;
        q[tail++] = s;
        vis[s] = true;
        while (head < tail) {
            int u = q[head++];
            for (auto& e : adj[u]) {
                if (e.cap > 0 && !vis[e.to]) {
                    vis[e.to] = true;
                    q[tail++] = e.to;
                }
            }
        }
        return vis;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j], g[i][j]--;

    auto get = [&](int r, int c) {
        return r * n + c;
    };
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
    auto da = [&](int r, int c) {
        return r >= 0 and r < n and c >= 0 and c < n;
    };
    int S = (n - 1) * n + n + n * n, T = (n - 1) * n + n + n * n + 1;
    Dinic d(T + 1);
    int R = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int id = get(i, j);
            d.add_edge(S, id, 1);
            if (g[i][j] != 0) {
                R++;
                d.add_edge(id + n * n, T, 1);
            }
            for (auto v : dirs) {
                int ni = i + v[0];
                int nj = j + v[1];
                if (da(ni, nj) and g[ni][nj] == g[i][j] + 1) {
                    int nid = get(ni, nj) + n * n;
                    d.add_edge(id, nid, 1);
                }
            }
        }
    }
    int flow = d.flow(S, T);
    if (flow == R) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}