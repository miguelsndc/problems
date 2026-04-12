#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, r, d, u; cin >> l >> r >> d >> u;
    long long ans = 0;
    for (int x = l; x <= r; x++) {
        int p = max(-abs(x) + 1, d);
        int q = min(u, abs(x) - 1);
        if (x % 2 == 0) ans += max(q - p + 1, 0); 
    }
    for (int y = d; y <= u; y++) {
        int p = max(-abs(y), l);
        int q = min(r, abs(y));
        if (y % 2 == 0) ans += max(q - p + 1, 0); 
    }
    cout << ans << '\n';
}