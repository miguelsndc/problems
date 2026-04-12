#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v))
struct BIT2D {
	vector<ll> ord;
	vector<vector<ll>> bit, coord;

	BIT2D(vector<pii> pts){
		sort(begin(pts), end(pts));

		for(auto [x, y] : pts)
			if(ord.empty() || x != ord.back())
				ord.push_back(x);

		bit.resize(ord.size() + 1);
		coord.resize(ord.size() + 1);

		sort(begin(pts), end(pts), [&](pii &a, pii &b){ return a.second < b.second; });

		for(auto [x, y] : pts)
			for(int i=upper(ord, x); i < bit.size(); i += i&-i)
				if(coord[i].empty() || coord[i].back() != y)
					coord[i].push_back(y);

		for(int i=0; i<bit.size(); i++) bit[i].assign(coord[i].size()+1, 0);
	}

	void update(ll X, ll Y, ll v){
		for(int i = upper(ord, X); i<bit.size(); i += i&-i)
			for(int j = upper(coord[i], Y); j < bit[i].size(); j += j&-j)
				bit[i][j] += v;
	}

	ll query(ll X, ll Y){
		ll sum = 0;
		for(int i = upper(ord, X); i > 0; i -= i&-i)
			for(int j = upper(coord[i], Y); j > 0; j -= j&-j)
				sum += bit[i][j];
		return sum;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n), b(n), c(n), p(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			p[i] = i;
		}
		sort(p.begin(), p.end(), [&](int i, int j) {
				return a[i] < a[j];
			});
		vector<pii> pts;
		for (int i = 0; i < n; i++) {
			pts.push_back({b[i], c[i]});
		}
		BIT2D bit(pts);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = b[p[i]];
			int y = c[p[i]];
			int q = bit.query(x - 1, y - 1);
			if (q == 0) {
				ans++;
			}
			bit.update(x, y, 1);
		}
		cout << ans << '\n';
	}
}
