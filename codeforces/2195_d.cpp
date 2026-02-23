#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<ll> f(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 2; i <= (n - 1); i++) {
        a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
    }
    a[n] = f[1], a[1] = f[n];
    for (ll i = 2; i <= n - 1; i++) {
        a[n] -= a[i] * (i - 1);
        a[1] -= a[i] * (n - i);
    }
    a[n] /= (n - 1);
    a[1] /= (n - 1);

    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];

}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}