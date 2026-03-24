#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int v = 2520, ms = 1e4 + 5, mod = 1e9 + 7;
int a[ms];
void add(i64 &x, i64 y) {
    x += y;
    if (x >= mod) x -= mod;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<i64> cur(v), prev(v);
    for (int i = 1; i <= n; i++) {
        cur = prev;
        add(cur[a[i] % v], 1);
        for (int j = 0; j < v; j++) {
            int novo = a[i] * j % v;
            add(cur[novo], prev[j]);
        }
        prev = cur;
    } 1954
    cout << prev[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
