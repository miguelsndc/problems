#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n, m; cin >> n >> m;
		vector<int> a(n + 1), b(m);
		multiset<int> even, odd;
		long long total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			total += a[i];
			if (i & 1) {
				odd.insert(a[i]);
			} else {
				even.insert(a[i]);
			}
		}
		/*
		invariante: paridade dos caras nunca muda independente das operacoes:
		qlqr cara em indice impar chega em qlqr indice impar e vice versa

		se query paridade = p
		marcou o primeiro ? nao entao marca
		qual o maior cara de paridade p ainda nao marcado ? se for positivo marca
		 */
		long long marcado = 0;
		const int inf = 1e9 + 1;
		bool pp = false, pi = false;
		for (auto &x: b) cin >> x;
		for (int x: b) {
			if (x & 1) {
				if(!pi) {
					int v = *odd.rbegin();
					marcado += v;
					odd.erase(odd.find(v));
					pi = true;
				} else {
					if(odd.empty()) continue;
					int v = *odd.rbegin();
					if (v > 0) marcado += v;
					if(odd.size() > 0 and v > 0) odd.erase(odd.find(v));
				}
			} else {
				if(!pp) {
					int v = *even.rbegin();
					marcado += v;
					even.erase(even.find(v));
					pp = true;
				} else {
					if(even.empty()) continue;
					int v = *even.rbegin();
					if (v > 0) marcado += v;
					if(even.size() > 0 and v > 0) even.erase(even.find(v));
				}
			}
		}
		cout << total - marcado << '\n';
	}
}
