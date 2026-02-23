#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int maxn = 3e5, mod = 1e9 + 7;
vector<ll> pw(maxn);
void dale() {
    int n; cin >> n;
    vector<ll> a(n); for (ll &i: a) cin >> i;
    if (rg::count(a, 0) == 0) {
        cout << 0 << "\n";
        return;
    }
    /*
    
        mex 1 = tem q ter algum zero + qlqr outro cara
        mex 1 = 2^(freq[0]) - 1 * (2^(qnts tem freq[i >= 2]));
        mex 2 = 2 * ((2^(freq[0]) - 1) * (2^freq[1] - 1) * 2 ^(qnts tem freq[i >= 3]))
        mex 3 = 3 * ((2^freq[0] - 1) * 2^(freq[1] - 1) * 2^freq([2] - 1) * 2^(qnts tem freq[i >= 4]));
    */

    vector<ll> freq(n + 1); ll maior = 0;
    for (int i = 0; i < n; i++) if (a[i] < n) {
        freq[a[i]]++;
    } else {
        maior++;
    }
    vector<ll> suffreq(n + 4);
    suffreq[n + 3] = suffreq[n + 2] = suffreq[n + 1] = suffreq[n] = maior;
    for (int i = n - 1; i >= 0; i--) {
        suffreq[i] = suffreq[i + 1] + freq[i];
    }
    ll ans = 0, prod = pw[freq[0]] - 1;
    // mex * (de quantas formas da pra fazer esse mex)
    for (ll mex = 1; mex <= n; mex++) {
        ll k = prod * (pw[suffreq[mex + 1]]) % mod;
        (ans += mex * (k)) %= mod;
        (prod *= pw[freq[mex]] - 1) %= mod;
    }
    cout << ans << '\n';
}
int main(){
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) pw[i] = (2ll * pw[i - 1]) % mod;
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}