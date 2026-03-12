#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int ans = 1;
    stack<int> st;
    st.push(a[0]);
    for (int i = 1; i < n; i++) {
        while(st.size() and st.top() != a[i] - 1) {
            st.pop();
        }
        if (st.empty()) {
            ans++;
        } 
        st.push(a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
