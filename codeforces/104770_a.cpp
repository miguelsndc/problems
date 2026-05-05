#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	long long dx = (n + k - 1) / k;
	long long dy = (m + k - 1) / k;
	cout << dx * dy;
}
