#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int maxn = 2e5 + 10;
vector g(maxn, vector<int>());
vector<int> subtree_size(maxn);
int get_sz(int u, int p = 0) {
    subtree_size[u] = 1;
    for (int v: g[u]) {
        if (v == p) continue;
        get_sz(v, u);
        subtree_size[u] += subtree_size[v];
    }
    return subtree_size[u];
}

int centroid(int u, int tree_sz, int p = -1) {
    for (int v: g[u]) {
        if (v == p) continue;
        if (subtree_size[v] * 2 > tree_sz) return centroid(v, tree_sz, u);
    }
    return u;
}

void dale() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    get_sz(1);
    cout << centroid(1, subtree_size[1]) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}