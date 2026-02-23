#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    vector<int> c(64);
    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            c[v]++;
        } else {
            for (int i = 30; i >= 0 and v > 0; i--) {
                if (c[i] > 0) {
                    ll x = max(min((v / (1 << i)), c[i]), 1);
                    ll val = (1ll << i) * x;
                    if (v >= val) {
                        v -= val;
                    }
                }
            }
            if (v == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
