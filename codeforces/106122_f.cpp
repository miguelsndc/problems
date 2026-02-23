#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    ll w, h, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;
    vector<ll> vx_cand = {x1 + x2, abs(x1 - x2)};
    vector<ll> vy_cand = {y1 + y2, abs(y1 - y2)};
    double min_t = -1.0;
    bool found = false;
    for (auto vx : vx_cand) {
        for (auto vy : vy_cand) {
            if (vx == 0 or vy == 0) continue;
            ll a = w * vy;
            ll b = h * vx;
            ll g = __gcd(a, b);
            a /= g;
            b /= g;
            if ((a & 1) and (b & 1)) {
                double t = (double)(w) * (double)(h) / (double)(g);
                if (!found || t < min_t) {
                    min_t = t;
                    found = true;
                }
            }
        }
    }
    if (found) {
        cout << setprecision(10) << fixed << min_t << '\n';
    } else {
        cout << -1 << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}