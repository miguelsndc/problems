#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 1e6 + 5;
int mu[mx], cnt[mx];
void prec() {
    mu[1] = -1;
    for (int i = 1; i < mx; i++) {
        if (mu[i]) {
            mu[i] = -mu[i];
            for (int j = 2 * i; j < mx; j += i) mu[j] += mu[i];
        }
    }
}
void dale() {
    prec();
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i, cnt[i]++;
    ll ans = 0;
    for (int i = 1; i < mx; i++) {
        if (mu[i] == 0) continue;
        ll d = 0;
        for (int j = i; j < mx; j += i) {
            d += cnt[j];
        }
        ans += d * (d - 1) / 2 * mu[i];
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}