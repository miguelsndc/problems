#include <bits/stdc++.h>
using namespace std;
/*
	cada componente é um range continuo
	um LR quebra um range em dois
	
	2 operacoes
		1 - conectar dois ranges
		2 - quebrar em dois ranges

	1 2 3 | 4 5
	1 4 2 | 3 5
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n, q; cin >> n >> q;
		vector<int> p(n);
		for (auto &x: p) cin >> x, --x;
		string s; cin >> s;
		vector<int> cut(n), pre(n);
		for (int i = 0; i + 1 < n; i++) {
			if (s[i] == 'L' and s[i + 1] == 'R') {
				cut[i] = true;
			}
		}
		pre[0] = p[0];
		for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], p[i]);
		/*
		   se max[1...i] > i (onde i é um corte) ent falso
		*/
		set<int> bad; // os cortes ruins, se sz(bad) == 0 gg
		for (int i = 0; i < n; i++) {
			if (!cut[i]) continue;
			if (pre[i] > i) {
				bad.insert(i);
			}
		}
		auto remove = [&] (int idx) {
			if (s[idx] == 'L' and s[idx + 1] == 'R') {
				bad.erase(idx);
			}
		};
		auto add = [&] (int idx) {
			if (s[idx] == 'L' and s[idx + 1] == 'R') {
				if (pre[idx] > idx) bad.insert(idx);
			}
		};
		while(q--) {
			int pos; cin >> pos; --pos;
			remove(pos - 1);
			remove(pos);
			s[pos] = (s[pos] == 'L' ? 'R' : 'L');
			add(pos - 1);
			add(pos);
			if ((int)(bad.size()) > 0) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}
