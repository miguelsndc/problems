#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n, m, k, x; cin >> n >> m >> k >> x;
    vector<int> s(n), w(n);
    for (int &i: s) cin >> i, i--;
    for (int &i: w) cin >> i;
    vector<vector<int>> sep(m);
    for (int i = 0; i < n; i++) {
        sep[s[i]].push_back(w[i]);
    }
    vector<int> amount(m, 1);
    for (auto &v: sep) sort(v.begin(), v.end());
    priority_queue<ii> pq;
    ll ans = 0, cap = k - m;
    for (int i = 0; i < sz(sep); i++) {
        ans += sep[i].back();
        for (int j = 0; j + 1 < sz(sep[i]); j++) {
            pq.push({sep[i][j], i});
        }
    }
    while(!pq.empty() and cap > 0) {
        auto [wt, species] = pq.top();
        pq.pop();
        if (amount[species] < x) {
            ans += wt;
            amount[species]++;
            cap--;
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}