#include <bits/stdc++.h>
using namespace std;
const int ms = 5e4 + 5;
vector<int> g[ms];
bitset<ms> reach[ms];
int vis[ms];
void dfs(int u) {
	vis[u] = true;
	for (int v: g[u]) {
		if (!vis[v]) dfs(v);
		reach[u] |= reach[v];
	}
	reach[u].set(u);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
	for (int i = 1; i <= n; i++) {
		cout << reach[i].count() << ' ';
	}
}

