#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, char> mp1, mp2;
    for (int i = 0; i < (int)(s.size()); i++) {
         if (mp1.count(s[i]) && mp1[s[i]] != t[i]) {
            cout << "NO\n";
            return;
        }
        if (mp2.count(t[i]) && mp2[t[i]] != s[i]) {
            cout << "NO\n";
            return;
        }
        
        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
