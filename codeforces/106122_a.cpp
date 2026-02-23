#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    ll n; cin >> n;
    if ((n * 10) % 8 == 0) {
        cout << 0 << '\n';
        return;
    }
    for (ll k = 1; k <= 8 * n; k++) {
        ll novo = n * pow(10, ((ll)log10(k) + 1)) + k;
        if (novo % 8 == 0) {
            cout << k << '\n';
            return;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}