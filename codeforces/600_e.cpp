#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int maxn = 1e5 + 10;
ll color[maxn], ans[maxn] = {0};
vector g(maxn, vector<int>());
map<ll, ll> freq[maxn];  // freq dos caras na subarvore u
map<ll, ll> sum[maxn];   // soma dos caras com frequencia u na subarvore j
void dfs(int u, int p = -1) {
    freq[u][color[u]]++;
    sum[u][1] += color[u];
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (freq[u].size() < freq[v].size()) {
            freq[u].swap(freq[v]);
            sum[u].swap(sum[v]);
        }
        for (auto [cor, cnt] : freq[v]) {
            if (freq[u].count(cor)) {
                sum[u][freq[u][cor]] -= cor;
            }
            freq[u][cor] += cnt;
            sum[u][freq[u][cor]] += cor;
        }
    }
    ans[u] = sum[u].rbegin()->second;
}
void dale() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}