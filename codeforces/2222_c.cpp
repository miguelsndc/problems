#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x: a) cin >> x;
		auto b = a;
		sort(b.begin(), b.end());
		int med = b[n/2];
		vector<int> p1(n + 1), p2(n + 1);
		for (int i = 0;i <n;i++){
			p1[i+1] = p1[i] + int(a[i] < med);
			p2[i+1] = p2[i] + int(a[i]>med);
		}
		vector<int> dp(n+1, -n);
		dp[0] = 0;
		for (int i=0;i<n;i++) {
			for (int j=i+1; j<=n; j += 2) {
				int metade = (j - i) / 2;	
				int k1 = p1[j] - p1[i];
				int k2 = p2[j] - p2[i];
				if (k1 <= metade and k2 <= metade) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
		cout << dp[n] << '\n';
	}
}
