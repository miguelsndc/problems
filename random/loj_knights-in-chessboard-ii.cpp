#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
  Hopcroft-Karp - Emparelhamento Máximo Bipartido
  Complexidade: O(E * sqrt(V)) constante melhor q dinic
================================================================================
  1. O grafo deve ser dividido em duas partições: Esquerda (tamanho 'n') e Direita (tamanho 'm').
  2. 1 indexado
  3. Adicione arestas sempre da ESQUERDA para a DIREITA: hk.add_edge(u, v);
  4. Chame hk.max_matching() para obter o tamanho do emparelhamento máximo.
  
================================================================================
*/

struct HopcroftKarp {
    int n, m;
    vector<vector<int>> adj;
    vector<int> matchL, matchR, dist;
    const int INF = 1e9;

    HopcroftKarp(int n, int m) : n(n), m(m), adj(n + 1), matchL(n + 1, 0), matchR(m + 1, 0), dist(n + 1, 0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (!matchL[u]) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INF;
            }
        }
        dist[0] = INF;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[matchR[v]] == INF) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
                }
            }
        }
        return dist[0] != INF;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[matchR[v]] == dist[u] + 1) {
                    if (dfs(matchR[v])) {
                        matchR[v] = u;
                        matchL[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }

    int max_matching() {
        int res = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (!matchL[u] && dfs(u)) {
                    res++;
                }
            }
        }
        return res;
    }
};
int dale() {
  int n, m, k;
  cin >> n >> m >> k;
  vector broken(n + 1, vector<int>(m + 1));
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    broken[r][c] = true;
  }
  vector<vector<int>> dir = {{2, -1}, {2, 1},   {1, -2},  {1, 2},
                             {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2}};
  auto posso = [&](int r, int c) {
    return r >= 1 and r <= n and c >= 1 and c <= m and !broken[r][c];
  };
  HopcroftKarp hk(n * m + m + 1, n * m + m + 1);
  auto id = [&](int r, int c) { return r * m + c; };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (broken[i][j] or (i + j) % 2) continue;
      for (auto& v : dir) {
        int dx = v[0], dy = v[1];
        if (!posso(i + dx, j + dy)) continue;
        hk.add_edge(id(i, j), id(i + dx, j + dy));
      }
    }
  }
  int total = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (broken[i][j]) continue;
        total++;
    }
  }
  return total - hk.max_matching();
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cout << "Case " << t << ": " << dale() << "\n"; 
  }
}