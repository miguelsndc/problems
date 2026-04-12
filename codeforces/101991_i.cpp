#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("icecream.in", "r", stdin);
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<int> c(n), h(n);
        for (auto &x: c) cin >> x;
        for (auto &x: h) cin >> x;
        int l = 0, r = *max_element(c.begin(), c.end()) + 1, ans = r;
        long long acc = 0;
        while(l <= r) {
            int m = l + (r - l) / 2;
            priority_queue<int> pq;
            for (int i = 0; i < n; i++) {
                if (c[i] <= m) {
                    pq.push(h[i]);
                } 
            }
            if (pq.size() < k) {
                l = m + 1;
            } else {
                long long cur = 0;
                for (int i = 0; i < k; i++) cur += pq.top(), pq.pop();
                ans = m;
                acc = cur;
                r = m - 1;
            }
        }
        cout << ans << ' ' << acc << '\n';
    }
}
