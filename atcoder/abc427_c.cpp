#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, m; cin >> n >> m;
    vector g(n, set<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].insert(--v);
        g[v].insert(u);
    }
    int arestas = m;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> cor(n);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) cor[j] = 1;
        }
        int cnt = 0;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (cor[u] == cor[v] and g[u].count(v)) {
                    cnt++;
                }
            }
        }
        arestas = min(arestas, cnt);
    }
    cout << arestas << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}