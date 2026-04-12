#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<long long> a(n), b;
        for (auto &x: a) cin >> x, x %= m;
        sort(a.begin(), a.end());
        b = {0};
        for (auto &x : a) b.push_back(x);
        for (auto &x : a) b.push_back(x + m);
        vector<long long> ps(sz(b));
        ps[0] = b[0];
        for (int i = 1; i < sz(b); i++) (ps[i] = ps[i - 1] + b[i]);
        long long ans = 1e18    ;
        for (int i = 0; i < n; i++) {
            ans = min(ans, ps[i + n] - ps[i + n - n /2] - ps[i + n / 2] + ps[i]);
        }
        cout << ans << '\n';
    }
}
