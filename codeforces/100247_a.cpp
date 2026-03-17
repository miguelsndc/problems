#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto& v : a) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
    }
    vector<array<int, 2>> pre(n + 1), suf(n + 1);
    pre[0] = {0, 0};
    suf[n] = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i + 1][j] = max(pre[i][j], a[i][j]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            suf[i][j] = max(suf[i + 1][j], a[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool ganha_antes = a[i][2] > pre[i][1] and a[i][1] > pre[i][0];
        bool ganha_dps = a[i][2] > suf[i + 1][1] and a[i][1] > suf[i + 1][0];
        if (ganha_antes and ganha_dps) {
            ans.push_back(i + 1);
        }
    };
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
