#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int L, n, t;
    cin >> L >> n >> t;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = l + (r - l) / 2.0;
        double x = 0, v = m, time = 0;
        bool ok = true;
        for (int j = 1; j < n; j++) {
            double pos = a[j];
            double nxt = x + v * (v / 2);
            if (nxt > pos) {
                double new_speed = sqrt(v * v - 2*(a[j] - x));
                x = pos;
                time += fabs(v - new_speed);
                v = new_speed + m;
            } else {
                ok = false;
                break;
            }
        }
        double nxt = x + v * (v / 2);
        if (nxt >= L) {
            double new_speed = sqrt(v * v - 2*(L - x));
            time += fabs(v - new_speed);
        } else {
            ok = false;
        }
        if (ok and time <= t) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(20) << fixed << (l + r) / 2 << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}