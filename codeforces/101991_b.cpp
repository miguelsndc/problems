#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("baklava.in", "r", stdin);
    const double pi = acos(-1.0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        double ans = (1e4) / (sin(pi / n) * sin(pi / n));
        cout << fixed << setprecision(5) << ans << '\n';
    }
}
