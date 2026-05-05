#include <bits/stdc++.h>
using namespace std;
struct cara {
    int L, R;
};
int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<cara> m(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        m[i] = {x - y, x + y};
    }
    sort(m.begin(), m.end(), [](const cara& a, const cara& b) {
        if (a.L == b.L) return a.R > b.R;
        return a.L < b.L;
    });
    
    int ans = 0;
    int max_R = -2e9; 
    for (int i = 0; i < n; i++) {
        if (m[i].R > max_R) {
            ans++;
            max_R = m[i].R;
        }
    }
    
    cout << ans << "\n";
    return 0;
}