#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<ld, ld> pdd;
#define x first
#define y second

ld dist(pdd p1, pdd p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

void dale() {
    ld s1x, s1y, e1x, e1y;
    ld s2x, s2y, e2x, e2y;
    cin >> s1x >> s1y >> e1x >> e1y;
    cin >> s2x >> s2y >> e2x >> e2y;

    ld d1 = hypot(e1x - s1x, e1y - s1y);
    ld d2 = hypot(e2x - s2x, e2y - s2y);

    pdd v1 = {0, 0}, v2 = {0, 0};
    if (d1 > 1e-12) v1 = {(e1x - s1x) / d1, (e1y - s1y) / d1};
    if (d2 > 1e-12) v2 = {(e2x - s2x) / d2, (e2y - s2y) / d2};

    auto get = [&](ld m) -> ld {
        pdd p1 = {s1x + min(m, d1) * v1.x, s1y + min(m, d1) * v1.y};
        pdd p2 = {s2x + min(m, d2) * v2.x, s2y + min(m, d2) * v2.y};
        return dist(p1, p2);
    };

    ld l = 0, r = max(d1, d2);
    for (int i = 0; i < 200; i++) { 
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;
        if (get(m1) > get(m2))
            l = m1;
        else
            r = m2;
    }

    cout << fixed << setprecision(10) << get((l + r) / 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) dale();
}
