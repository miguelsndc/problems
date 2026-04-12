#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n, m; cin >> n >> m;
		vector<string> s(n); vector<int> c(n);
		for (int i = 0; i < n; i++) cin >> s[i] >> c[i];
		int L = m / 2;
		int R = m - L;
		vector<int> ans_L(n), ans_R(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < L; j++) if (s[i][j] == '1') ans_L[i] |= (1 << j);
			for (int j = 0; j < R; j++) if (s[i][L + j] == '1') ans_R[i] |= (1 << j);
		}
		vector<pair<long long, int>> estados_r;
		for (int mask = 0; mask < (1 << R); mask++) {
			long long estado = 0;
			for (int i = 0; i < n; i++) {
				int aqui = ~(mask ^ ans_R[i]) & ((1 << R) - 1);
				estado = (estado << 5) | __builtin_popcount(aqui);
			}
			estados_r.push_back({estado, mask});
		}
		sort(estados_r.begin(), estados_r.end());
		long long sols = 0; string best = "";
		for (int mask = 0; mask < (1 << L); mask++) {
			long long estado = 0;
			bool ok = true;
			for (int i = 0; i < n; i++) {
				int aqui = ~(mask ^ ans_L[i]) & ((1 << L) - 1);
				int req = c[i] - __builtin_popcount(aqui);
				if (req < 0 or req > R) {
					ok = false;
					break;
				}
				estado = (estado << 5) | req;
			}
			if (!ok) continue;

			int i1 = lower_bound(estados_r.begin(), estados_r.end(), make_pair(estado, -1)) - estados_r.begin();
			int i2 = upper_bound(estados_r.begin(), estados_r.end(), make_pair(estado, (1 << 30))) - estados_r.begin();
			long long cnt = i2 - i1;
			if (cnt > 0) {
				sols += cnt;
				if (sols == cnt and best == "") {
					int rmask = estados_r[i1].second;
					for (int j = 0; j < L; j++) best += ((mask & (1 << j)) ? '1' : '0');
                    for (int j = 0; j < R; j++) best += ((rmask & (1 << j)) ? '1' : '0');}
			}
		}
		if (sols == 1) cout << best << '\n';
        else cout << sols << " solutions\n";
	}
}
