#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int ms = 1e5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n, t; cin >> n >> t;
		vector<int> c(n);
		vector<int> dist(ms, inf), vis(ms, false);
		for (auto &x: c) cin >> x;
		queue<int> q;
		q.push(0);
		vis[0] = true;
		dist[0] = 0;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (int x: c) {
				int v = max(0, min(3600, u + x));
				if (vis[v]) continue;
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		for (int x = t; x < ms; x++) {
			if (dist[x] != inf) {
				cout << dist[x] << ' ' << x - t << '\n';
				break;
			}
		}
	}
}
