#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int mxn = 1e7 + 1;
bool prime[mxn]; int spf[mxn];
void sieve() {
    fill(prime, prime + mxn, true);
    fill(spf, spf + mxn, -1);
    prime[0] = prime[1] = false;
    spf[0] = spf[1] = 1;
    for (ll i = 2; i * i< mxn; i++) {
        if (prime[i]) {
            spf[i] = i;
            for (ll j = i * i; j < mxn; j += i) {
                prime[j] = false;
                if (spf[j] == -1) spf[j] = i;
            }
        }
    }
}
void dale() {
    sieve();
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<pii> ans(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        vector<int> factors;
        int k = a[i];
        while(k > 1) {
            int f = spf[k];
            factors.push_back(f);
            while (k % f == 0) k /= f;
        }
        if (sz(factors) == 1) continue;
        int m = (sz(factors) - 1) / 2;
        int d1 = factors[0], d2 = 1;
        for (int i = 1; i < sz(factors); i++) {
            d2 *= factors[i];
        }
        ans[i] = {d1, d2};
    }
    for (auto [x, y]: ans) cout << x << ' ';
    cout << '\n';
    for (auto [x, y]: ans) cout << y << ' ';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}