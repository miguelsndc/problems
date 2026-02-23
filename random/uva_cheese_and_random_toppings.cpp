#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#define sz(x) ((int)(x).size())
const int ms = 55;
int C[ms][ms][ms];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
inline ll fix(ll x, ll mod) {x %= mod; if (x < 0) x += mod; return x;}
struct mdc { ll x, y, d; };
mdc euclides_ext(ll a, ll b) {
    if (b == 0) return {1, 0, a};
    mdc p = euclides_ext(b, a % b);
    return {p.y, p.x - a / b * p.y, p.d};
}

pll crt(vector<pll> congruences) {
    for (auto &[x, y]: congruences) x = fix(x, y);
    auto [ans, lcm] = congruences[0];
    for (int i = 1; i < sz(congruences); i++) {
        auto [a, n] = congruences[i];
        auto [x, y, d] = euclides_ext(lcm, n);
        ans = fix(ans + (ll)(x * (a - ans) / d % (n / d)) * lcm, lcm * n / d);
        lcm = lcm * n / d;
    }
    return {ans, lcm};
}

void prec() {
    memset(C, 0, sizeof(C));
    for (int p : primes) {
        C[0][0][p] = 1; 
        for (int i = 1; i < ms; i++) {
            C[i][0][p] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j][p] = (C[i - 1][j - 1][p] + C[i - 1][j][p]) % p;
            }
        }
    }
}

ll lucas(ll n, ll r, ll p) {
    ll res = 1;
    while (n > 0 || r > 0) {
        ll ni = n % p, ri = r % p;
        if (ri > ni) return 0;
        res = (res * C[ni][ri][p]) % p;
        n /= p; r /= p;
    }
    return res;
}

void dale() {
    ll n, r, m; 
    cin >> n >> r >> m;
    vector<pll> cong;
    for (auto p : primes) {
        if (m % p == 0) {
            cong.emplace_back(lucas(n, r, p), p);
        }
    }
    if (m == 1) { 
        cout << 0 << "\n";
    } else {
        auto [ans, lcm] = crt(cong);
        cout << (ll)ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    prec();
    int tt; cin >> tt;
    while(tt--) dale();
    return 0;
}