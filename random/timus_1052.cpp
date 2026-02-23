#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n;
    cin >> n;
    map<pii, int> mp;
    vector<pii> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    const long double EPS = 1e-9;
    int ans = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int vx = (points[j].first - points[i].first);
            int vy = (points[j].second - points[i].second);
            if (vx < 0) {
                vx *= -1;
                vy *= -1;
            }
            int g = __gcd(vx, vy);
            vx /= g;
            vy /= g;
            int cur = 2;
            for (int k = 0; k < n; k++) {
                if (k == i or k == j) continue;
                int zx = (points[k].first - points[j].first);
                int zy = (points[k].second - points[j].second);
                if (zx < 0) {
                    zx *= -1;
                    zy *= -1;
                }
                int gg = __gcd(zx, zy);
                zx /= gg;
                zy /= gg;
                if (zx == vx and zy == vy) cur++;
            }
            ans = max(ans,cur);
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}