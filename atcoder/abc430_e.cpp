#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
using ll = long long;
const ll M1 = 188888881, M2 = 1e9 + 7, B = 137;
const int MAXN = 2e6 + 5;
ll p1[MAXN], p2[MAXN];
bool hashcalc = false;
struct Hash {
    vector<pair<ll, ll>> h;
    Hash(const string& s) {
        if (!hashcalc) {
            p1[0] = p2[0] = 1;
            for (int i = 1; i < MAXN; i++) {
                p1[i] = (p1[i - 1] * B) % M1;
                p2[i] = (p2[i - 1] * B) % M2;
            }
            hashcalc = true;
        }
        int n = s.size();
        h.assign(n + 1, {0, 0});
        for (int i = 0; i < n; i++) {
            h[i + 1].first  = (h[i].first * B + s[i]) % M1;
            h[i + 1].second = (h[i].second * B + s[i]) % M2;
        }
    }
    // Returns O(1) combined 64-bit hash of the inclusive substring [l, r].
    ll operator()(int l, int r) {
        int len = r - l + 1;
        ll h1 = (h[r + 1].first  - (h[l].first * p1[len]) % M1 + M1) % M1;
        ll h2 = (h[r + 1].second - (h[l].second * p2[len]) % M2 + M2) % M2;
        return (h1 << 32) | h2;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        string a, B; cin >> a >> B;
        string A = a;
        for (char c: a) A += c;
        Hash h_A(A), h_B(B);
        ll full_b = h_B(0, sz(B) - 1);
        bool ok = false;
        for (int i = 0; i < sz(a); i++) {
            if (h_A(i, i + sz(a) - 1) == full_b) {
                ok = true;
                cout << i << '\n';
                break;
            }
        }
        if(!ok) cout << -1 << '\n';
    }   
}