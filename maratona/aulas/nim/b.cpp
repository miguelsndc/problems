#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		int x = 0;
		for (int i = 0; i < n; i++) {
			int y; cin >> y;
			x ^= y;
		}
		if (x != 0) {
			cout << "first\n";
		} else {
			cout << "second\n";
		}
	}
}

