#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

/*
    4
    abacaba
    tetatet
    test a b c a
    bear a b c d
    vector<int> mp[26]
    a -> 1,3,5,7
    b -> 2,6
    c- -> 4
*/

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (string& s : g) cin >> s;
    for (string& s : g) {
        map<char, char> mp;
        char cur = 'a';
        for (auto& c : s) {
            if (!mp.count(c)) mp[c] = cur++;
            c = mp[c];
        }
        // cout << s << '\n';
    }
    map<string, i64> mp;
    i64 ans = 0;
    for (auto s: g) {
        ans += mp[s];
        mp[s]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
