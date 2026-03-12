#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n & 1 and s[0] == 'b') {
        cout << "NO\n";
        return;
    }
    int start = (n & 1 ? 1: 0);
    for (int i = start; i + 1 < n; i += 2) {
        if (s[i] != '?' and s[i + 1] != '?' and s[i] == s[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
