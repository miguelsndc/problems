#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve(int c) {
    array<bitset<10001>, 3> f;
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            f[i].set(x, 1);
        }
    }
    array<vector<int>, 3> solved;
    int mx = 0;
    for (int i = 0; i <= 2; i++) {
        int a = (i + 1) % 3;
        int b = (i + 2) % 3;
        auto other = f[a] | f[b];
        auto didnt = ~other;
        auto none = f[i] & didnt;
        mx = max(mx, (int)none.count());
        vector<int> cur;
        for (int b = 0; b < (int)(none.size()); b++) {
            if (none[b]) solved[i].push_back(b);
        }
    }
    cout << "Case #" << c << ":\n";
    for (int i = 0; i < 3; i++) {
        if ((int)solved[i].size() == mx) {                                                                                              
            cout << i + 1 << " " << mx;
            for (int x : solved[i]) cout << " " << x;
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        solve(t);
    }
}
