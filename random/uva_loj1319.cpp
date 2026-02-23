#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll ,ll>;
#define sz(x) ((int)(x).size())
inline ll fix(ll x, ll mod) {x %= mod; if (x < 0) x += mod; return x;}
inline long long LCM(long long a, long long b) { return a / __gcd(a, b) * b; }
struct mdc { ll x, y, d; };
mdc euclides_ext(ll a, ll b) {
    if (b == 0) return {1, 0, a};
    mdc p = euclides_ext(b, a % b);
    return {p.y, p.x - a / b * p.y, p.d};
}
const ll inf = 1e18;
pll crt(vector<pll> congruences) {
    for (auto &[x, y]: congruences) fix(x, y);
    auto [ans, lcm] = congruences[0];
    for (int i = 1; i < sz(congruences); i++) {
        auto [a, n] = congruences[i];
        auto [x, y, d] = euclides_ext(lcm, n);
        if ((a - ans) % d != 0) return {inf, inf};
        ans = fix(ans + x * (a - ans) / d % (n / d) * lcm, lcm * n / d);
        lcm = lcm * n / d;
    }
    return {ans, lcm};
}

void dale(int c) {
    int n; cin >> n;
    vector<pll> a(n);
    for (auto &p: a) cin >> p.second >> p.first;
    auto [ans, lcm] = crt(a);
    if (ans == inf) {
        cout << "Impossible\n";
        return;
    }
    cout << "Case " << c << ": " << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        dale(i);
    }
}