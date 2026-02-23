#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    vector<int> freq(61);
    for (int i = 0; i < n; i++) {
        int msb = -1;
        for (int bit = 60; bit >= 0; bit--) {
            if (a[i] & (1ll << bit)) {
                msb = bit;
                break;
            }
        }
        if (msb >= 0) {
            freq[msb]++;
        }
    }
    int ans = 1;
    for (int i = 0; i <= 60; i++) {
        ans = max(ans, freq[i]);
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}