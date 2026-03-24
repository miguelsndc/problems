#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end(), [&] (const auto&v1, const auto&v2){
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1];
        }
        return v1[0] > v2[0];
    });
    int bound = n;
    int op = 0;
    for (auto &[val, pos]: a)  {
        if (pos >= bound) continue;
        op++;
        bound = pos;
    }
    cout << op << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
