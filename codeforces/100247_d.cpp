#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string s;
    for (int i = 0; i < n; i++) {
        map<char, int> freq;
        freq[a[i]]++;
        freq[b[i]]++;
        freq[c[i]]++;
        char ans = a[i]; int fr = 0;
        for (auto [ch, f]: freq) {
            if (f > fr) {
                fr = f;
                ans = ch;
            }
        }
        s += ans;
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
