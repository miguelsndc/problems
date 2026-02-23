#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) {
        int n, s; cin >> n >> s;
        if (((s & 1) and n % 2 == 0) || s > 9LL * n || (s == 0 && n > 1)) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(n, 0);
        int l = 0, r = n - 1;
        bool ok = true;
        while(l <= r) {
            bool found = false;
            for (int i = 9; i >= (l == 0 && n > 1 ? 1 : 0); i--) {
                if (l < r) {
                    if (s >= 2 * i && s - 2 * i <= 9LL * (r - l - 1)) {
                        ans[l] = ans[r] = i;
                        s -= 2 * i;
                        found = true;
                        break;
                    }
                } else {
                    if (s == i) {
                        ans[l] = ans[r] = i;
                        s -= i;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) { ok = false; break; }
            l++, r--;
        }
        if (!ok or s > 0) cout << -1 << '\n';
        else {
            for (int x: ans) cout << x;
            cout << '\n';
        }
    }
}