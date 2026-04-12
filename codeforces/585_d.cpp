#include <bits/stdc++.h>
using namespace std;
vector<array<int, 3>> L, R;
/*
	quero que haja um k tal que
	x1 + x2 = k
	y1 + y2 = k
	z1 + z2 = k
 */
void brute(int i, vector<array<int,3>> &v, int x, int y, int z, unsigned long long hist) {
	if (i == v.size()) {
		// result
	}
	brute(i + 1, v, x + v[i][0], y + v[i][1], z, (hist << 3) | 6); // 110
	brute(i + 1, v, x + v[i][0], y, z + v[i][2], (hist << 3) | 5); // 101
	brute(i + 1, v, x, y + v[i][1], z + v[i][2], (hist << 3) | 3); // 011
}; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<array<int,3>> a(n);
	for (auto &[x,y,z]:a)cin>>x>>y>>z;
	int mid = n / 2;
	for (int i = 0; i < mid; i++) L.push_back(a[i]);
	for (int i = mid; i < n; i++) R.push_back(a[i]);
}
