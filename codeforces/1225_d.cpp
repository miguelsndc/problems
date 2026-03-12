#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int mx = 1 + *max_element(a.begin(), a.end());
    vector<int> primo(mx + 1, 1), lpf(mx + 1);
    primo[0] = primo[1] = 0;
    iota(lpf.begin(), lpf.end(), 0);
    for (int i = 2; i <= mx; i++) {
        if (primo[i]) {
            for (int j = i << 1; j <= mx; j += i) {
                primo[j] = false;
                lpf[j] = min(lpf[j], i);
            }
        }
    }
    map<vector<ii>, ll> mp;
    auto get = [&](int i, int k) {
        int x = a[i];
        vector<ii> fac;
        while (x > 1) {
            int f = lpf[x], pow = 0;
            while (x % f == 0) {
                x /= f;
                pow++;
            }
            if (pow % k > 0) {
                fac.push_back({f, pow % k});
            }
        }
        return fac;
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto v = get(i, k);
        auto rev = v;
        for (auto& [fac, pmodk] : rev) {
            pmodk = k - pmodk;
        }
        if (mp.count(rev)) {
            ans += mp[rev];
        }
        mp[v]++;
    }
    cout << ans << '\n';
}
