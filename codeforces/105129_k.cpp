#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    bool ok = false;
    for (int i = 0; i + 1 < n; i++) {
        ok |= s[i] == '1' and s[i + 1] == '0';
        ok |= s[i] == '1' and s[i + 1] == '1';
    }
    cout << (ok ? "YES\n": "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
