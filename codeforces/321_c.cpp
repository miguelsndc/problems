#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mxn = 1e5 + 10;
int sz[mxn], removed[mxn], ans[mxn];
vector<int> g[mxn];
int get_sz(int u, int p = -1) {
    int &s = sz[u];
    s = 1;
    for (int v: g[u]) if (v != p and !removed[v]) {
        get_sz(v, u);
        s += sz[v];
    }
    return s;
}
int centroid(int u, int tam, int p = -1) {
    for (int v: g[u]) if (v != p and !removed[v]) {
        if (sz[v] * 2 > tam) return centroid(v, tam, u);
    }
    return u;
}
void decompose(int u = 1, int x = 0) {
    int c = centroid(u, get_sz(u));
    ans[c] = x;
    removed[c] = true;
    for (int v: g[c]) if (!removed[v]) {
        decompose(v, x + 1);
    }
}
void dale() {
    memset(sz, 0, sizeof sz);
    memset(removed, 0, sizeof removed);
    memset(ans, 0, sizeof ans);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decompose();
    for (int i = 1; i <= n; i++) {
        cout << char(ans[i] + 'A') << ' ';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}