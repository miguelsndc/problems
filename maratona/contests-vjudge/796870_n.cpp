#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

struct pt {
    i64 x, y, d = 1;
};
struct reta {
    i64 a, b, c;
};
reta mediatriz(const pt& p1, const pt& p2) {
    reta res;
    res.a = 2 * (p2.x - p1.x);
    res.b = 2 * (p2.y - p1.y);
    res.c = (p2.x * p2.x - p1.x * p1.x) + (p2.y * p2.y - p1.y * p1.y);
    return res;
}

pair<bool, pt> intersect(const reta& l1, const reta& l2) {
    i64 D = l1.a * l2.b - l2.a * l1.b;
    if (D == 0) {
        return {false, {-1, -1}};
    }
    pt res;
    res.x = l1.c * l2.b - l2.c * l1.b;
    res.y = l1.a * l2.c - l2.a * l1.c;
    res.d = D;
    return {true, res};
}

int resolve(const pt& cand, vector<pt>& pts) {
    set<i128> s;
    for (auto& [x, y, d] : pts) {
        i128 dx = (cand.x - x * cand.d);
        i128 dy = (cand.y - y * cand.d);
        s.insert(dx * dx + dy * dy);
    }
    return s.size();
}

void solve() {
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    vector<pt> candidatos = pts;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            i64 px = pts[i].x + pts[j].x;
            i64 py = pts[i].y + pts[j].y;
            candidatos.push_back({px, py, 2});
        }
    }
    vector<reta> retas;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            reta med = mediatriz(pts[i], pts[j]);
            retas.push_back(med);
        }
    }
    int m = (int)(retas.size());
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            auto inter_pt = intersect(retas[i], retas[j]);
            if (inter_pt.first) {
                candidatos.push_back(inter_pt.second);
            }
        }
    }
    int ans = 1e9;
    for (auto &c: candidatos) {
        ans = min(ans, resolve(c, pts));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
