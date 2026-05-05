#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
	s[l:r] pode ser rearranjada em duas strings 
	se toda ocorrencia de caracter for par
	freq[c][r] - freq[c][l - 1] % 2 == 0
	freq[c][r] == freq[c][l] (mod 2) pra c E [0, 9]
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int n = (int)(s.size());
	map<vector<int>, int> mp;
	vector<int> v(10);
	mp[v] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int k = (int)(s[i] - '0');
		v[k] = (v[k] + 1) % 2;
		ans += mp[v];
		mp[v]++;
	}
	cout << ans;
}

