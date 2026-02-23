#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int x, y, k;
    cin >> x >> y >> k;

    auto nxt = [&](int v) {
        int d = (((v + y - 1) / y) * y);
        return d;
    };

    if (x % y == 0 and k > 0) {
        k--, x++;
        while (x % y == 0) x /= y;
    }

    int q = 0;
    while (k >= (nxt(x) - x)) {
        k -= nxt(x) - x;
        x += (nxt(x) - x);
        while (x % y == 0) x /= y;
        q++;
        if (x == 1) break;
    }
    k %= (y - 1);
    x += k;
    while (x % y == 0) x /= y;
    cout << x << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}