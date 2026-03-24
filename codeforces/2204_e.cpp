#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    string s; cin >> s;
    int n = (int)(s.size());
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    do {
        for (int i = 0; i < n; i++) {
            cout << s[ord[i]];
        }
        cout << "\n\n";
    } while(next_permutation(ord.begin(), ord.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
