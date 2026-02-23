#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    ll mx = a[0], cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < mx) cnt += mx - a[i];
        mx = max(mx, (ll)a[i]);
    }
    cout << cnt << '\n';
}