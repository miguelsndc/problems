#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> t(n), d(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> d[i];
    priority_queue<int> pq;
    int ans = 0, vida = 0, last = 0;
    for (int i = 0; i < n; i++) {
        vida += (t[i] - last);
        last = t[i];
        
        vida -= d[i];
        pq.push(d[i]);

        while (pq.size() > 0 and vida < 0) {
            int k = pq.top();
            pq.pop();
            vida += k;
            ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
