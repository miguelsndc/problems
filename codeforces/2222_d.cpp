#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n), order(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			order[i] = i;
		}
		vector<long long> pre(n + 1);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = pre[i] + a[i];
		}
		sort(order.begin(), order.end(), [&] (int i, int j) {
				return pre[i] < pre[j];
		});
		vector<int> pos(n);
		for (int i = 0; i < n; i++) {
			pos[order[i]] = n - 1 - i;
		}
		for (int i = 0; i < n; i++) {
			cout << pos[i] + 1 << " \n"[i == n - 1];
		}
	}
}

