#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	long long num = 0, pow = 1, ans = 0;
	map<int, int> mp;
	mp[0] = 1;
	for (int i = (int)(s.size()) - 1; i >= 0; i--) {	
		int val = (int)(s[i] - '0');
		num = (num + pow * val % 2019) % 2019;
		ans += mp[num];
		mp[num]++;
		pow = (pow * 10) % 2019;
	}
	cout << ans;
}

