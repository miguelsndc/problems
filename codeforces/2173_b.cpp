#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    ll mn = 0;
    ll mx = 0;
    for(int i = 0; i < n; ++i) {
        ll nxt_mx = max(mx - a[i], b[i] - mn);
        ll nxt_mn = min(mn - a[i], b[i] - mx);
        mx = nxt_mx;
        mn = nxt_mn;
    }
    cout << mx << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}