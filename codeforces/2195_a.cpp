#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    bool ok = false;
    for (int bit = 0; bit < (1 << n); bit++) {
        int prod = 1;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                prod *= a[i];
            }
        }
        if (prod == 67) {
            ok = true;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}