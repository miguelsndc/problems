#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, m; cin >> n >> m;
    vector<ll> a(n); for (ll &i: a) cin >> i;
    sort(a.begin(), a.end());
    vector<ll> d;
    for (int i = 1; i < n; i++) {
        d.push_back(a[i] - a[i - 1]);
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    for (int i = 0; i < n-m; i++) {
        ans += d[i];
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}