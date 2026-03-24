#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (auto &x: v) cin >> x;
    string target, ans = "";
    for (int i = 0; i + 1 < n; i++) {
        target += v[i];
        target += (i < n - 1 ? " " : "");
    }
    target += v[n - 1];
    int q; cin >> q;
    int upper = false;
    while(q--) {
        string s; cin >> s;
        if (s == "CapsLock") {
            upper ^= 1;
        } else if (s == "Backspace") {
            if (ans.size() > 0) ans.pop_back();
        } else if (s == "Space") {
            ans += ' ';
        } else {
            char v = s[0];
            char nxt = (upper ? toupper(v) : v);
            ans += nxt;
            // cout << nxt << ' ' << upper << '\n';
        }
    }
    if (ans == target) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
