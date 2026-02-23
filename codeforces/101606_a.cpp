#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    for (auto& [x, y, z] : a) cin >> x >> y >> z;
    auto noite = [&](int x, int i) {
        auto [p, s, e] = a[i];
        x %= p;
        if (s < e) {
            return (x <= s or x >= e);
        }
        return !((x > s and x <= (p - 1)) or (x >= 0 and x < e));
    };
    int total = 1825, p = 1;
    for (int i = 0; i < n; i++) {
        auto [pe, k7, k8] = a[i];
        p = max(p, pe);
    }
    total *= p;
    for (int i = 0; i <= total; i++) {
        bool tudo = true;
        for (int j = 0; j < n; j++) {
            tudo &= noite(i, j);
        }
        if (tudo) {
            cout << i << '\n';
            return;
        }
    }

    cout << "impossible\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}