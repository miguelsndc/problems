#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while (tt--) {
		int n, k; cin >> n >> k;
		vector<int> a(n + 2);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int p; cin >> p;
		a[0] = a[n + 1] = a[p];
		int l =0, r= 0 ;
		for (int i =0; i < p; i++) if (a[i] != a[i + 1]) l++;
		for (int i =p; i < n + 1; i++) if (a[i] != a[i + 1]) r++;
			cout << max(l,r) << '\n';
	}
}
