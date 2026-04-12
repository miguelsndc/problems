#include <bits/stdc++.h>
using namespace std;
const int ms = 2e5 + 10;
int d[ms], pre[ms];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, q; cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		d[l]++; d[r + 1]--;
	}
	for (int i = 1; i < ms; i++) { 
		d[i] += d[i - 1];
	}
	for (int i = 0; i < ms; i++) {
		pre[i] = (int)(d[i] >= k);
	}
	for (int i = 1; i < ms; i++) {
		pre[i] += pre[i - 1];
	}
	while(q--) {
		int a, b; cin >> a >> b;
		cout << pre[b] - pre[a - 1] << '\n';
	}
}
