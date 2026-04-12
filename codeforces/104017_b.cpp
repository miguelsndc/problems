#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int age; cin >> age;
            v.push_back({age, i, j});
        }
    }
    sort(v.begin(), v.end());
    vector<int> row(n), col(n), x(n * n + 1), y(n * n + 1);
    for (auto &[age, r, c]: v) {
        int cr = row[r];
        int cc = col[c];
        x[age] = cr; y[age] = cc;
        row[r]++;
        col[c]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n * n; i++) {
        ans += x[i] * (n - 1 - y[i]) + y[i] * (n - 1 - x[i]);
    }
    cout << ans / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
