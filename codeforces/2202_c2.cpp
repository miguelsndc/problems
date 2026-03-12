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
    i64 ans = 0, cur = 0;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() and a[st.top()] == a[i] + 1) {
            int pop_idx = st.top();
            cur -= (n - pop_idx); // ele nao é o engolidor 
            st.pop();
        }
        st.push(i);
        cur += (n - i);
        ans += cur;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
