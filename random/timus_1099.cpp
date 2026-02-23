#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Blossom {
    int n;
    vector<vector<int>> adj;
    vector<int> match, p, base, q;
    vector<bool> inq, inb;
    vector<int> head;
    int head_cnt;

    // Construtor 1-indexado
    Blossom(int n) : n(n), adj(n + 1), match(n + 1, 0), p(n + 1, 0), 
                     base(n + 1, 0), q(n + 1, 0), inq(n + 1, 0), 
                     inb(n + 1, 0), head(n + 1, 0), head_cnt(0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lca(int root, int u, int v) {
        ++head_cnt;
        while (true) {
            if (u) {
                if (head[u] == head_cnt) return u;
                head[u] = head_cnt;
                u = base[p[match[u]]];
            }
            swap(u, v);
        }
    }

    void mark_blossom(int lca, int u) {
        while (base[u] != lca) {
            int v = match[u];
            inb[base[u]] = inb[base[v]] = true;
            u = p[v];
            if (base[u] != lca) p[u] = v;
        }
    }

    void bfs(int root) {
        fill(p.begin(), p.end(), 0);
        fill(inq.begin(), inq.end(), false);
        for (int i = 1; i <= n; ++i) base[i] = i;
        
        int qh = 0, qt = 0;
        q[qt++] = root;
        inq[root] = true;

        while (qh < qt) {
            int u = q[qh++];
            for (int v : adj[u]) {
                if (base[u] == base[v] || match[u] == v) continue;
                if (v == root || (match[v] && p[match[v]])) {
                    int cur_lca = lca(root, u, v);
                    fill(inb.begin(), inb.end(), false);
                    mark_blossom(cur_lca, u);
                    mark_blossom(cur_lca, v);
                    if (base[u] != cur_lca) p[u] = v;
                    if (base[v] != cur_lca) p[v] = u;
                    for (int i = 1; i <= n; ++i) {
                        if (inb[base[i]]) {
                            base[i] = cur_lca;
                            if (!inq[i]) {
                                inq[i] = true;
                                q[qt++] = i;
                            }
                        }
                    }
                } else if (!p[v]) {
                    p[v] = u;
                    if (!match[v]) {
                        for (int curr = v, nxt; curr; curr = nxt) {
                            nxt = match[p[curr]];
                            match[curr] = p[curr];
                            match[p[curr]] = curr;
                        }
                        return;
                    }
                    inq[match[v]] = true;
                    q[qt++] = match[v];
                }
            }
        }
    }

    int solve() {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!match[i]) {
                bfs(i);
                if (match[i]) ans++;
            }
        }
        return ans; 
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    int a, b;
    Blossom blossom(n);
    while((cin >> a >> b)) {
        blossom.add_edge(a, b);
    }
    int pares = blossom.solve();
    cout << pares * 2 << "\n";
    for (int i = 1; i <= n; i++) {
        if (blossom.match[i] > i) {
            cout << i << ' ' << blossom.match[i] << '\n';
        }
    }
}