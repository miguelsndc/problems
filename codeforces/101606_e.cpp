#include <bits/stdc++.101606h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void dale() {
    int n, m; cin >> n >> m;
    vector<int> s(n), p(m), r(m), z(m), w(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> r[i];
    for (int i = 0; i < m; i++) z[i] = i;
    for (int i = 0; i < n; i++) w[i] = i;
    sort(z.begin(), z.end(), [&] (int v1, int v2) {
        return p[v1] > p[v2];
    });
    sort(w.begin(), w.end(), [&] (int v1, int v2) {
        return s[v1] > s[v2];
    });
    int hi = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> ans(n, -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        while(hi < m and p[z[hi]] >= s[w[i]]) pq.push({r[z[hi]], z[hi] + 1}), hi++;
        if (pq.size()) {
            ans[w[i]] = pq.top().second;
            pq.pop();
        } else {
            ok = false;
        }
    }
    if (!ok) {
        cout << "impossible\n";
        return;
    }
    for (int x: ans) cout << x << ' ';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}