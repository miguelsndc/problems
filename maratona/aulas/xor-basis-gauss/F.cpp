#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxsz = 200;
int placed[maxsz], posto = 0;
bitset<maxsz> basis[105];
int insert(bitset<maxsz> &b, int dim) {
    for (int i = dim - 1; i >= 0; i--) if (b[i]) {
        if (!placed[i]) {
            basis[i] = b;
            placed[i] = true;
            posto++;
            return false;
        } else {
            b ^= basis[i];
        }
    }
    return b[dim];
};
void dale() {
    memset(placed, false, sizeof placed);
    int p, f; cin >> p >> f;
    vector g(p, vector<int>());
    for (int i = 0; i < f; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    bool inconsistente = false;
    for (int cara = 0; cara < p; cara++) {
        bitset<maxsz> b;
        for (int v: g[cara]) {
            b[v] = 1;
        }
        if (g[cara].size() % 2 == 1) b[cara] = 1;
        b[p] = 1;
        inconsistente |= insert(b, p);
    }
    cout << (!inconsistente ? "Y\n": "N\n");
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}