#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int S = accumulate(a.begin(), a.end(), 0);
    double l = 0, r = 1e4 + 1;
    for (int i = 0; i < 300; i++) {
        double mid = (l + r) / 2;
        int ps = a[1];
        double m = ps - mid;
        bool ok = false;
        for (int j = 2; j <= n - 1; j++) {
            ps += a[j];
            double cara = (n - j) * mid - S + ps;
            if (cara >= m) {
                ok = true;
            }
            m = min(m, ps - mid * j);
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << setprecision(3) << fixed << l;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    int tt = 1; // cin >>   tt;
    while(tt--) slve();
}