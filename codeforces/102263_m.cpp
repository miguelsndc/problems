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
    string ans;
    sort(s.rbegin(), s.rend());
    for (int i = 0; i < n; i++) {
        ans += s[i];
        while(ans.size() > 1 and ans.back() == ans[ans.size() - 2] and ans.back() < 'z') {
            char x = ans.back();
            ans.pop_back(); ans.pop_back();
            ans.push_back(x + 1);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
