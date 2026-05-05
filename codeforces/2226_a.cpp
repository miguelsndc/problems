#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
const int mod = 676767677;
void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int cnt1 = count(a.begin(), a.end(), 1);
    if (cnt1 == n) {
        cout << 1 << '\n';
        return;
    }
    ll ans = 0, other = 0, has = 0;
    while(a.size() > 0 and a.back() == 1) {
        has = true;
        a.pop_back();
    }
    if (has) ans++;

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != 1) {
            ans += a[i];
        }
    }
    cout << ans % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}