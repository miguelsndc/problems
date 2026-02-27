#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dinic {
    struct Edge {
        int to, rev;
        ll cap, flow = 0;
    };

    vector<vector<Edge>> adj;
    vector<int> lvl, ptr;
    int n, s, t;

    Dinic(int n, int s, int t)
        : n(n)
        , s(s)
        , t(t)
        , adj(n)
        , lvl(n)
        , ptr(n)
    {
    }

    void add_edge(int u, int v, ll cap, bool rev = false)
    {
        adj[u].push_back({ v, (int)adj[v].size(), cap, 0 });
        adj[v].push_back({ u, (int)adj[u].size() - 1, rev ? cap : 0, 0 });
    }

    bool bfs()
    {
        fill(lvl.begin(), lvl.end(), -1);
        lvl[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : adj[u]) {
                if (e.cap - e.flow > 0 && lvl[e.to] == -1) {
                    lvl[e.to] = lvl[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return lvl[t] != -1;
    }

    ll dfs(int u, ll pushed)
    {
        if (pushed == 0 || u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < adj[u].size(); ++cid) {
            auto& e = adj[u][cid];
            ll tr = e.to;
            if (lvl[u] + 1 != lvl[e.to] || e.cap - e.flow == 0)
                continue;

            ll push = dfs(e.to, min(pushed, e.cap - e.flow));
            if (push == 0)
                continue;

            e.flow += push;
            adj[e.to][e.rev].flow -= push;
            return push;
        }
        return 0;
    }

    ll flow()
    {
        ll f = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, 1e18)) {
                f += pushed;
            }
        }
        return f;
    }

    vector<bool> get_reachable()
    {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : adj[u]) {
                if (e.cap - e.flow > 0 && !vis[e.to]) {
                    vis[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return vis;
    }
};
void bop()
{
    int n, m;
    cin >> n >> m;
    int src = 0, sink = n - 1;
    Dinic d(n, src, sink);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        d.add_edge(a, b, 1);
    }
    int f = d.flow();
    cout << f << '\n';
    vector<vector<int>> paths;
    while(f--) {
        int curr = src;
        vector<int> path{curr};
        while (curr != sink) {
            for (auto &e: d.adj[curr]) {
                if (e.flow == 1) {
                    e.flow = 0;
                    curr = e.to;
                    break;
                }
            }
            path.push_back(curr);
        }
        paths.push_back(path);
    }
    for (auto &p: paths) {
        cout << p.size() << '\n';
        for (int x: p) cout << x + 1<< ' ';
        cout << '\n';
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        bop();
}