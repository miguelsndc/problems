#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1e9 + 7;
int main(){
    ifstream fin("barnpainting.in");
    fin.sync_with_stdio(false);
    fin.tie(nullptr);
    int n, k; fin >> n >> k;
    vector g(n + 1, vi());
    for (int i = 0; i < n - 1; i++) {
        int u, v; fin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector dp(n + 1, vector<ll>(4));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= 3; j++)
            dp[i][j] = 1;

    for (int i = 0; i < k; i++) {
        int node, color; fin >> node >> color;
        for (int j = 1; j <= 3; j++) dp[node][j] = 0;
        dp[node][color] = 1;
    }

    function <void(int,int)> dfs = [&] (int u, int p) {
        for (int v: g[u]) {
            if (v != p) {
                dfs(v, u);
                // pinto de x e o filho de (outro ou outro2)
                (dp[u][1] *= (dp[v][2] + dp[v][3]) % mod) %= mod;
                (dp[u][2] *= (dp[v][1] + dp[v][3]) % mod) %= mod;
                (dp[u][3] *= (dp[v][2] + dp[v][1]) % mod) %= mod;
            }
        }
    };

    dfs(1, 0);

    ofstream("barnpainting.out") << (dp[1][1] + dp[1][2] + dp[1][3]) % mod;
}