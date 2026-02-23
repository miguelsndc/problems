#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void dale() {
    int tx, ty;
    cin >> tx >> ty;
    int n;
    cin >> n;
    struct lizard {
        int x, y, h;
    };
    vector<lizard> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].h;
    }
    map<pii, int> mp;
    int cur = 0;
    vector<vector<lizard>> por_vetor;
    for (auto [x, y, h] : a) {
        int vx = tx - x;
        int vy = ty - y;
        int g = __gcd(abs(vx), abs(vy));
        vx /= g;
        vy /= g;
        if (mp.count({vx, vy})) {
            por_vetor[mp[{vx, vy}]].push_back({x, y, h});
        } else {
            mp[{vx, vy}] = cur++;
            por_vetor.push_back({{x, y, h}});
        }
    }
    auto lds = [&] (vector<int> &v) {
        if (v.empty()) return 0;
        vector<int> tail(v.size(), 0);
        int len = 1;
        tail[0] = v[0];
        for (int i = 1; i < v.size(); i++) {
            auto b = tail.begin(), e = tail.begin() + len;
            auto it = lower_bound(b, e, v[i], greater<>());
            if (it == tail.begin() + len) tail[len++] = v[i];
            else *it = v[i];
        }
        return len;
    };

    int ans = 0;
    for (auto v: por_vetor) {
        sort(v.begin(), v.end(), [&] (const lizard& v1, const lizard & v2) {
            ll d1 = (ll)(v1.x - tx) * (v1.x - tx) + (ll)(v1.y - ty) * (v1.y - ty);
            ll d2 = (ll)(v2.x - tx) * (v2.x - tx) + (ll)(v2.y - ty) * (v2.y - ty);
            return d1 > d2;
        });
        vector<int> heights;
        for (int i = 0; i < (int)v.size(); i++) heights.push_back(v[i].h);
        int cur = lds(heights);
        ans += cur;
    }

    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}