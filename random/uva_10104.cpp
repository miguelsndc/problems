#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())

inline ll fix(ll x, ll mod) {x %= mod; if (x < 0) x += mod; return x;}
inline long long LCM(long long a, long long b) { return a / __gcd(a, b) * b; }

struct mdc { ll x, y, d; };
mdc euclides_ext(ll a, ll b) {
    if (b == 0) return {1, 0, a};
    mdc p = euclides_ext(b, a % b);
    return {p.y, p.x - a / b * p.y, p.d};
}

void dale() {
    ll a, b, n, m;
    cin >> a >> n >> b >> m;
    a %= n, b %= m;
    ll ans = a, lcm = n;
    auto [x, y, d] = euclides_ext(lcm, m);
    if ((b - ans) % d != 0) {
        cout << "no solution\n";
        return;
    }
    ans = fix(ans + x * (b - ans) / d % (m / d) * lcm, lcm * m / d);
    lcm = lcm * m / d;
    cout << ans << ' ' << lcm << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while (tt--) dale();
    return 0;
}
