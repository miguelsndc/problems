#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FastBitset {
    using ull = unsigned long long;
    vector<ull> bits;
    vector<unsigned short> pref; 
    int n;

    void init(int _n) {
        n = _n;
        int num_blocks = (n + 63) >> 6;
        bits.assign(num_blocks, 0);
    }

    void set(int idx) {
        bits[idx >> 6] |= (1ULL << (idx & 63));
    }

    void operator|=(const FastBitset& other) {
        for (size_t i = 0; i < bits.size(); ++i) {
            bits[i] |= other.bits[i];
        }
    }

    void build_prefix() {
        pref.resize(bits.size() + 1);
        pref[0] = 0;
        for (size_t i = 0; i < bits.size(); ++i) {
            pref[i + 1] = pref[i] + (unsigned short)__builtin_popcountll(bits[i]);
        }
    }

    int count_range(int L, int R) {
        if (L > R) return 0;
        int l_blk = L >> 6;
        int r_blk = R >> 6;

        if (l_blk == r_blk) {
            ull mask = (~0ULL << (L & 63));
            if ((R & 63) < 63) {
                mask &= ~(~0ULL << ((R & 63) + 1));
            }
            return __builtin_popcountll(bits[l_blk] & mask);
        }

        int ans = 0;
        ans += __builtin_popcountll(bits[l_blk] & (~0ULL << (L & 63)));
        ans += (int)pref[r_blk] - (int)pref[l_blk + 1];
        ull end_mask = ~0ULL; 
        if ((R & 63) < 63) {
             end_mask = ~(~0ULL << ((R & 63) + 1));
        }
        ans += __builtin_popcountll(bits[r_blk] & end_mask);

        return ans;
    }
};

const int ms = 50010;
vector<vector<int>> g(ms), dag(ms);
int visited[ms], vis[ms], roots[ms];
FastBitset reach[ms];

void solve_reach(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : dag[u]) {
        solve_reach(v);
        reach[u] |= reach[v];
    }
}

void dfs(int v, vector<vector<int>>& adj, vector<int>& output) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) dfs(u, adj, output);
    }
    output.push_back(v);
}

void scc(vector<vector<int>>& adj, int n) {
    vector<int> order;
    
    fill(visited, visited + n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, adj, order);
    }

    vector<vector<int>> adj_transp(n);
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            adj_transp[u].push_back(v);
        }
    }

    fill(visited, visited + n, false);
    reverse(order.begin(), order.end());
    
    for (int v : order) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj_transp, component);
            int root = component[0]; 
            
            reach[root].init(n); 

            for (auto u : component) {
                roots[u] = root;
                reach[root].set(u);
            }
        }
    }

    for(int i=0; i<n; ++i) dag[i].clear();
    
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            if (roots[v] != roots[u]) {
                dag[roots[v]].push_back(roots[u]);
            }
        }
    }
}

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;

    for (int i = 0; i < n; i++) {
        g[i].clear();
        vis[i] = 0;
        reach[i].bits.clear();
        reach[i].bits.shrink_to_fit();
        reach[i].pref.clear();
        reach[i].pref.shrink_to_fit();
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
    }

    scc(g, n); 

    for (int i = 0; i < n; i++) {
        if (roots[i] == i && !vis[i]) {
            solve_reach(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (roots[i] == i) {
            reach[i].build_prefix();
        }
    }

    while (q--) {
        ll k; cin >> k;
        int ans = 0;
        
        for (int bit = 29; bit >= 0; bit--) {
            ll cnt = 0;
            int target = ans | (1 << bit);
            int mask = ~((1 << bit) - 1);

            for (int u = 0; u < n; u++) {
                int val = u + 1;
                int req = target ^ (val & mask);
                
                int L = max(0, req - 1);
                int R = min((req + (1 << bit) - 1) - 1, n - 1);

                if (L > R) continue;

                int root = roots[u];
                cnt += reach[root].count_range(L, R);
            }

            if (cnt >= k) ans |= (1 << bit);
            else k -= cnt;
        }
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) solve();
}