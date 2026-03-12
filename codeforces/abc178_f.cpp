#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), f1(n + 1), f2(n + 1);
    for (auto &x: a) cin >> x, f1[x]++;
    for (auto &x: b) cin >> x, f2[x]++;
    for (int i = 1; i <= n; i++) {
        if (f1[i] + f2[i] > n) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    reverse(b.begin(), b.end());
    bool left = true;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) continue;
        if (b[l] != b[i] and left) {
            swap(b[l++], b[i]);
            left ^= 1;
        } else {
            swap(b[r--], b[i]);
            left ^= 1;
        }
    }
    for (int x: b) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
