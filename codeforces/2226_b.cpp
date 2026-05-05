#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (abs(a[i] - a[i + 1]) == std::gcd(a[i], a[i + 1])) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}