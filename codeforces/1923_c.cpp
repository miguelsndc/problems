#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 3e5 + 10;
int c[ms];
void dale() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<ll> ps(n + 1), f1(n + 1);
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + c[i];
    for (int i = 0; i < n; i++) f1[i + 1] = f1[i] + (c[i] == 1);
    while(q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO\n";
            continue;
        }
        ll tam = r - l + 1;
        ll sum = ps[r] - ps[l - 1];
        ll f = f1[r] - f1[l - 1];
        int livre = tam - f;
        sum -= tam;
        if (sum < f) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}