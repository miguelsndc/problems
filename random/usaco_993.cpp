#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::ifstream fin("time.in");
    std::ofstream fout("time.out");
    int n, m, c; fin >> n >> m >> c;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) fin >> a[i];
    vector g(n + 1, vi());
    for (int i = 0; i < m; i++) {
        int u, v; fin >> u >> v;
        g[u].push_back(v);
    }
    vector<vi> dp(n + 1, vi(1005, -1));
    dp[1][0] = 0;
    ll ans = 0;
    for (int T = 0; T < 1000; T++) {
        for (int city = 1; city <= n; city++) {
            if (dp[city][T] == -1) continue;
            for (int v: g[city]) {
                if (T + 1 < 1000)
                    dp[v][T + 1] = max(dp[v][T + 1], dp[city][T] + a[v]);
            }
        }
        ans = max(ans, 1ll * dp[1][T] - 1ll * c * T * T);
    }
    fout << ans << '\n';
}