#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		auto y_vertice = [&] (int a, int b, int c) {
			double xv = (double)-b / (2 * a);
			double yv = (double)a * xv * xv + b * xv + c;
			cout << " x do vertice = " << xv << " y do vertice = " << yv << '\n';
			return yv;
		};
		double mx = -1e9; int ans = -1;
		for (int i = 0; i < n; i++) {
			double yv = y_vertice(-a[i], b[i], c[i]);
			if (yv > mx) {
				mx = yv;
				ans = i + 1;
			}
		}
		cout << ans << '\n';
	}
}
