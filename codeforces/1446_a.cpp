#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; i64 W; cin >> n; cin >> W;
    vector<int> w(n), ord(n);
    iota(ord.begin(), ord.end(), 0);
    for (auto &x: w) cin >> x;
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return w[i] < w[j];
    });
    i64 sum = 0; bool found = false;
    vector<int> chosen;
    for (int i = 0; i < n; i++) {
        if (w[i] >= (W + 1) / 2 and w[i] <= W) {
            cout << 1 << '\n';
            cout << i + 1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        i64 x = w[ord[i]];
        if (sum + x <= W) sum += x, chosen.push_back(ord[i] + 1);
        if (sum >= (W + 1) / 2) found = true;
    }
    sort(chosen.begin(), chosen.end());
    if (found) {
        cout << chosen.size() << '\n';
        for (int x: chosen) cout << x << ' ';
        cout << '\n';
    } else  {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
