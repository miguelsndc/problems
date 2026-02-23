#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
const ll limit = 1e15;
ll lcm(ll a, ll b) {
    if (a > limit or b > limit) return limit + 1;
    ll g = __gcd(a, b);
    if (a > limit / (b / g)) return limit + 1;
    return (a / g) * b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> ps(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
        vector<pair<ll,ll>> lcms;
        for (int r = 0; r < n; r++) {
            vector<pair<ll, ll>> nxt;
            nxt.push_back({a[r], r});
            for (auto &[p, i]: lcms) {
                ll novo = lcm(p, a[r]);
                if (nxt.back().first == novo) {
                    nxt.back().second = i;
                } else {
                    nxt.push_back({novo, i});
                }
            }
            lcms = nxt;
            int rb = r;
            for (auto &[p, l]: lcms) {
                if (p > limit) {rb = l - 1; continue;}
                
                for (int i = l; i <= rb; i++) {
                    if ((ps[r + 1] - ps[i]) % p == 0) {
                        cnt++;
                    }
                }

                rb = l - 1;
            }
        }
        cout << cnt << '\n';
    }
}