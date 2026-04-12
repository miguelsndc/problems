#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	set<char> st;
	string s; cin >> s;
	for (auto &x: s) st.insert(x);
	int max_size = (int)st.size(), ans = n, distinct = 0;
	st.clear();
	map<int, int> freq;
	int l = 0;
	for (int r = 0; r < n; r++) {
		st.insert(s[r]);
		if (++freq[s[r]] == 1) {
            distinct++;
		}
		if (l == r and distinct == max_size) ans = 1;
		while(l < r and distinct == max_size) {
			ans = min(ans, r - l + 1);
			if (--freq[s[l]] == 0) {
				st.erase(s[l]);
                distinct--;
			}
            l++;
		}
	}
	cout << ans << '\n';
}
