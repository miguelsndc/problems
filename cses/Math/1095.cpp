#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fexp(ll a, ll b, ll m) {
    ll ans = 1;
    while(b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}
const int mod = 1e9 + 7;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cout << fexp(a, b, mod) << '\n';
    }
}