#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    ll operator%(const pt& a) const { return x * a.y - y * a.x; } 
    bool operator<(const pt& a) const { return x != a.x ? x < a.x : y < a.y; }
    bool operator==(const pt& a) const { return x == a.x && y == a.y; }
};
vector<pt> ch(vector<pt> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 1) return pts;
    int n = pts.size(), k = 0;
    vector<pt> h(2 * n);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && (h[k-1] - h[k-2]) % (pts[i] - h[k-2]) > 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n-2, t = k; i >= 0; i--) {
        while (k > t && (h[k-1] - h[k-2]) % (pts[i] - h[k-2]) > 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k-1);
    return h;
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<pt> a(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }

    vector<pt> hull = ch(a);
    long double ans = 0;
    int m = hull.size();
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        ans += hypotl(hull[j].x - hull[i].x, hull[j].y - hull[i].y);
    }

    long double res = ans + (4.0L) * l * sqrtl(2.0L);
    cout << fixed << setprecision(10) << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}
