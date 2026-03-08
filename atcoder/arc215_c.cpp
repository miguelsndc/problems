#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
struct BIT {
    int n;
    vector<ll> bit;
    BIT(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum [0..pos] (0-based)
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
void solve() {
    int n;
    cin >> n;
    struct cara {
        int x, y, z;
    };
    vector<cara> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    sort(A.begin(), A.end(), [&](const cara& v1, const cara& v2) {
        if (v1.x == v2.x) {
            if (v1.y == v2.y) {
                return v1.z > v2.z;
            }
            return v1.y > v2.y;
        }
        return v1.x > v2.x;
    });

    vector<int> minY(n), minZ(n), maxY(n), maxZ(n);
    minY[0] = A[0].y;
    minZ[0] = A[0].z;
    for (int i = 1; i < n; i++) {
        minY[i] = min(minY[i - 1], A[i].y);
        minZ[i] = min(minZ[i - 1], A[i].z);
    }
    maxY[n - 1] = A[n - 1].y;
    maxZ[n - 1] = A[n - 1].z;
    for (int i = n - 2; i >= 0; i--) {
        maxY[i] = max(maxY[i + 1], A[i].y);
        maxZ[i] = max(maxZ[i + 1], A[i].z);
    }

    int ans = n;
    for (int k = 0; k + 1 < n; k++) {
        if (A[k].x > A[k + 1].x and minY[k] > maxY[k + 1] and
            minZ[k] > maxZ[k + 1]) {
            ans = k + 1;
            break;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
}
