#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dinic {
    struct Edge {
        int to, rev;
        ll cap;
    };
    vector<vector<Edge>> adj;
    vector<int> lvl, ptr, q;
    int n;

    Dinic(int n) : n(n), adj(n), lvl(n), ptr(n), q(n) {}

    void add_edge(int u, int v, ll cap) {   
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0});
    }

    bool bfs(int s, int t) {
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

    ll dfs(int u, int t, ll pushed) {
        if (pushed == 0 || u == t) return pushed;
        for (int& cid = ptr[u]; cid < adj[u].size(); ++cid) {
            auto& e = adj[u][cid];
            if (lvl[u] + 1 != lvl[e.to] || e.cap == 0) continue;
            ll tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0) continue;
            e.cap -= tr;
            adj[e.to][e.rev].cap += tr;
            return tr;
        }
        return 0;
    }

    ll flow(int s, int t) {
        ll f = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, t, 1e18)) {
                f += pushed;
            }
        }
        return f;
    }
    
    vector<bool> get_reachable(int s) {
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
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    vector<vector<int>> direcoes = {
        { a, b }, { b, a }, { b, -a }, { a, -b },
        { -a, -b }, { -b, -a }, { -b, a }, { -a, b }
    };

    auto posso = [&](int r, int c) {
        return r >= 0 and r < n and c >= 0 and c < n and board[r][c] != '#';
    };
    int k = 0;
    if ((a | b) != 0)
        k = __builtin_ctz(a | b);
    int sa = a >> k, sb = b >> k;
    auto cor = [&](int r, int c) {
        if ((sa + sb) % 2 == 1)
            return ((r >> k) + (c >> k)) % 2;
        return (r >> k) % 2;
    };
    auto get_id = [&](int r, int c) {
        return r * n + c;
    };

    int S = n * n, T = n * n + 1;
    Dinic dinic(n * n + 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#')
                continue;
            int u = get_id(i, j);
            int c = cor(i, j);
            if (c == 0) {
                dinic.add_edge(S, u, 1);
                for (auto v : direcoes) {
                    int ni = i + v[0];
                    int nj = j + v[1];
                    if (posso(ni, nj)) {
                        int v = get_id(ni, nj);
                        dinic.add_edge(u, v, 1);
                    }
                }
            } else {
                dinic.add_edge(u, T, 1);
            }
        }
    }
    dinic.flow(S, T);
    vector<bool> reachable = dinic.get_reachable(S);
    vector<string> ans = board;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#')
                continue;
            int u = get_id(i, j);
            int c = cor(i, j);
            bool boto = false;
            if (c == 0) {
                if (reachable[u])
                    boto = true;
            } else {
                if (!reachable[u])
                    boto = true;
            }
            if (boto)
                ans[i][j] = 'o';
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}