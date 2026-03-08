#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mxn = 1005;
int m, a, b;
vector vis(mxn, vector<int>(mxn));
vector<vector<int>> g(mxn * mxn, vector<int>()); 
vector<int> seen(mxn * mxn);
void dfs(int node) {
    seen[node] = true;
    for (int v: g[node]) {
        if (seen[v]) continue;
        dfs(v);
    };
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int ni = j;
            int nj = (a * j % m + b * i % m) % m;
            g[ni * m + nj].push_back(i * m + j);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <  m; j++) {
            if (i == 0 or j == 0) {
                if(!seen[i * m + j]) dfs(i * m + j);
            }
        }
    }
    cout << m * m - accumulate(seen.begin(), seen.end(), 0);
}
