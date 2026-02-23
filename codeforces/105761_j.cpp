#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mxn = 1e6 + 5, mod = 1e9 + 7;
ll fat[mxn];
ll inv(ll a, ll b = mod - 2) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll comb(ll n, ll k) {
    return (fat[n] * inv(fat[k]) % mod) * (inv(fat[n - k])) % mod;
}
ll no_formas(int dx, int dy) {
    return comb(dx + dy, dx);
}
void dale() {
    int n;
    cin >> n;
    vector<ii> obstaculo(n);
    for (auto& [x, y] : obstaculo) cin >> x >> y;
    sort(obstaculo.begin(), obstaculo.end());
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int min_x = min(x1, x2), max_x = max(x1, x2);
        int min_y = min(y1, y2), max_y = max(y1, y2);
        vector<ii> na_bb;
        // pega so quem tiver no caminho
        for (auto& [x, y] : obstaculo) {
            if (x >= min_x and x <= max_x and y >= min_y and y <= max_y) {
                na_bb.push_back({abs(x1 - x), abs(y1 - y)});
            }
        }
        // normaliza pra ser de 0,0 ate fim
        int dest_x = abs(x1 - x2);
        int dest_y = abs(y1 - y2);
        na_bb.push_back({dest_x, dest_y});
        sort(na_bb.begin(), na_bb.end());
        vector<ll> dp(sz(na_bb));
        for (int i = 0; i < sz(na_bb); i++) {
            dp[i] = no_formas(na_bb[i].first, na_bb[i].second);
            for (int j = 0; j < i; j++) {
                if (na_bb[j].first <= na_bb[i].first and na_bb[j].second <= na_bb[i].second) {
                    ll caminho_ji = no_formas(na_bb[i].first - na_bb[j].first, na_bb[i].second - na_bb[j].second);
                    dp[i] = (dp[i] - (dp[j] * caminho_ji) % mod + mod) % mod;
                }
            }
        }
        cout << dp.back() % mod << '\n';
    }
}
int main() {
    fat[0] = 1;
    for (ll i = 1; i < mxn; i++) (fat[i] = fat[i - 1] * i % mod) %= mod;
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}