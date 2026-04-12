#include <bits/stdc++.h>
using namespace std;
/*
	minimizar maior soma de dois pares
	sorta e junta as pontas
	two pointers pq se qtd da esquerda for != qtd da direita tenho q andar pra dentro com o que sobrar
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n), q(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> q[i] >> a[i];
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&] (int i, int j) {
		return a[i] < a[j];
	});
	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {
		int m = min(q[p[l]], q[p[r]]);
		ans = max(ans, a[p[l]] + a[p[r]]);
		q[p[l]] -= m;
		if (l < r) {
			q[p[r]] -= m;
		}
		if (q[p[l]] == 0) l++;
		if (q[p[r]] == 0) r--;
	}
	cout << ans << '\n';
}
