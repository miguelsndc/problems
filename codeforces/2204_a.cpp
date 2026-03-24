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
    int cur = 0; set<int> st{0};
    for (int i = 0; i < n; i++) {
        if (s[cur] == 'R') {
            cur++;
            st.insert(cur);
        } else {
            cur--;
            st.insert(cur);
        }
    }
    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
