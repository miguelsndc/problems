#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int number = 0;
		reverse(s.begin(), s.end());
		for (int j = 0; j < k; j++) {
			if (s[j] == '1') {
				number |= (1 << j);
			}
		}
		a[i] = number;
	}
	int mindist = k;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			mindist = min(mindist, __builtin_popcount(a[i] ^ a[j]));
			if (mindist == 0) break;
		}
		if (mindist == 0) break;
	}
	cout << mindist;
}


