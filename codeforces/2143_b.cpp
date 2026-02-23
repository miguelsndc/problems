#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k), free(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    ll ans = 0;
    int i = b[0] - 1;
    free[i] = true;
    for (int j = 1; j < k; j++) {
        i += b[j];
        if (i < n) free[i] = true; 
        else break;
    }
    for (int i = 0; i < n; i++) {
        if (!free[i]) ans += a[i];
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) dale();
}