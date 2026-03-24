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
    vector mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int ms = (1 << n);
    vector<i64> score(ms, 0);
    for (int mask = 0; mask < ms; mask++) {
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                if (mask & (1 << x) and mask & (1 << y)) {
                    score[mask] += mat[x][y];
                }
            }
        }
    }
    vector<i64> sos(ms, 0);
    for (int mask = 0; mask < ms; mask++) {
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            sos[mask] = max(sos[mask], sos[mask ^ sub] + score[sub]);
        }
    } 
    cout << sos[ms - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
