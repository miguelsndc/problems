#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ex, ey;
    cin >> n >> ex >> ey;
    string s;
    cin >> s;
    int dx, dy;
    if (s == "NORTH") {
        dx = 0, dy = 1;
    } else if (s == "NORTHEAST") {
        dx = 1, dy = 1;
    } else if (s == "EAST") {
        dx = 1;
        dy = 0;
    } else if (s == "SOUTHEAST") {
        dx = 1;
        dy = -1;
    } else if (s == "SOUTH") {
        dx = 0, dy = -1;
    } else if (s == "SOUTHWEST") {
        dx = -1;
        dy = -1;
    } else if (s == "WEST") {
        dx = -1;
        dy = 0;
    } else {
        dy = 1;
        dx = -1;
    }
    ll mind = 1e18, ansx = 0, ansy = 0, found = false;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        ll vx = x - ex, vy = y - ey;
        if (x == ex and y == ey) {
            ansx = x; ansy = y;
            found = true;
            mind = 0;
            break;
        }
        ll g = __gcd(llabs(vx), llabs(vy));
        if ((vx / g) == dx and (vy / g) == dy) {
            if (mind > vx * vx + vy * vy) {
                mind = vx * vx + vy * vy;
                ansx = x;
                ansy = y;
                found = true;
            }
        }
    }
    if (!found) {
        cout << -1 << '\n';
    } else {
        cout << ansx << ' ' << ansy << '\n';
    }
}