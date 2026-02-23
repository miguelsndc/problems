#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e7 + 5, mod = 998244353;
int spf[ms]; vector<int> primo;
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void sieve() {
    for (int i = 2; i < ms; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primo.push_back(i);
        }
        for (int j = 0; i * primo[j] < ms; j++) {
            spf[i * primo[j]] = primo[j];
            if (primo[j] == spf[i]) break;
        }
    }
}
void dale() {
    int n; cin >> n;
    vector<int> A(n);
    for (auto &i: A) cin >> i;
    struct Primo {
        int mx1 = -1, mx2 = -1, cnt_mx1 = 0;
    };
    map<int,Primo> mp;
    vector<vector<pair<int,int>>> fator(n);
    ll lcm = 1;
    for (int i = 0; i < n; i++) {
        int k = A[i];
        while(k > 1) {
            int p = 0, f = spf[k];
            while(k % f == 0) k /= f, p++;
            fator[i].push_back({f, p});
            if (!mp.count(f)) {
                mp[f] = {p, -1, 1};
            } else {
                auto &[mx1, mx2, cnt_mx1] = mp[f];
                if (p > mx1) {
                    mx2 = mx1;
                    mx1 = p;
                    cnt_mx1 = 1;
                } else if (p == mx1) {           
                    cnt_mx1++;         
                } else if (p > mx2) {
                    mx2 = p;
                }
            }
        }
    }
    for (auto &[x, y]: mp) {
        lcm =(lcm * fexp(x, y.mx1)) % mod;
    }
    for (int i = 0; i < n; i++) {
        ll ans = lcm;
        for (auto [f, p]: fator[i]) {
            if (p == mp[f].mx1 and mp[f].cnt_mx1 == 1) {
                ans = (ans * fexp(fexp(f, p), mod - 2)) % mod;
                if (mp[f].mx2 != -1) {
                    ans = (ans * fexp(f, mp[f].mx2)) % mod;
                }
            }
        }
        cout << ans << " \n"[i == n - 1];
    }
}
int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}