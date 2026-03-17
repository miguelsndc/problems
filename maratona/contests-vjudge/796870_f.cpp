#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int inf = 1e9;
struct res {
    int mx;
    pair<int,int> range;
};

res faz(vector<int>& a) {
    int n = (int)(a.size());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int ps = 0;
    pq.push({0, -1});
    res ans = {-inf, {0, 0}};
    for (int i = 0; i < n; i++) {
        ps += a[i];
        int newmx = ps - pq.top().first;
        if(ans.mx < newmx) {
            ans.mx = newmx;
            ans.range = {pq.top().second + 1, i};
        } else if(ans.mx == newmx) {
            int nl = pq.top().second + 1;
            pair<int,int> b = {nl, i};
            ans.range = min(ans.range, b);
        }
        pq.push({ps, i});
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int n = (int)(s.size());
    vector<int> pos(n), neg(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            pos[i] = 1;
            neg[i] = -1;
        } else {
            pos[i] = -1;
            neg[i] = 1;
        }
    }
    auto neg_result = faz(neg);
    auto pos_result = faz(pos);
    if (pos_result.mx > neg_result.mx) {
        cout << pos_result.range.first + 1 << ' ' << pos_result.range.second + 1 << '\n';
    } else if (neg_result.mx > pos_result.mx){
        cout << neg_result.range.first + 1 << ' ' << neg_result.range.second + 1 << '\n';
    } else {
        auto ans = min(pos_result.range, neg_result.range);
        cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
