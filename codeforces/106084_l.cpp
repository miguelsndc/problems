#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
};

ll cross(pt o, pt a, pt b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool no_segmento(pt p, pt a, pt b) {
    return p.x >= min(a.x, b.x) and p.x <= max(a.x, b.x) and
           p.y >= min(a.y, b.y) and p.y <= max(a.y, b.y);
}

bool segmento_intersecta(pt a, pt b, pt c, pt d) {
    ll cp1 = cross(c, d, a);
    ll cp2 = cross(c, d, b);
    ll cp3 = cross(a, b, c);
    ll cp4 = cross(a, b, d);
    if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) &&
        ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0))) {
        return true;
    }

    if (cp1 == 0 && no_segmento(a, c, d)) return true;
    if (cp2 == 0 && no_segmento(b, c, d)) return true;
    if (cp3 == 0 && no_segmento(c, a, b)) return true;
    if (cp4 == 0 && no_segmento(d, a, b)) return true;

    return false;
}

bool is_inside(pt p, pt min_corn, pt max_corn) {
    return p.x >= min_corn.x && p.x <= max_corn.x &&
           p.y >= min_corn.y && p.y <= max_corn.y;
}

bool solve() {
    pt bl, tr, p1, p2;
    cin >> bl.x >> bl.y >> tr.x >> tr.y;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    pt br = {tr.x, bl.y};
    pt tl = {bl.x, tr.y};
    if (is_inside(p1, bl, tr) or is_inside(p2, bl, tr)) {
        return true;
    }

    if (segmento_intersecta(p1, p2, bl, br)) return true;
    if (segmento_intersecta(p1, p2, bl, tl)) return true;
    if (segmento_intersecta(p1, p2, br, tr)) return true;
    if (segmento_intersecta(p1, p2, tl, tr)) return true;

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "STOP\n": "OK\n");
    }
}