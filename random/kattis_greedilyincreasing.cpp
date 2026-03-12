#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> p(n), nxt(n, -1);
    for (auto &x: p) cin >> x, --x;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while(st.size() and p[st.top()] < p[i]) st.pop();
        if (st.size()) nxt[i] = st.top();
        st.push(i);
    }
    vector<int> ans; int cur = 0;

    do {
        ans.push_back(p[cur]);
        cur = nxt[cur];
    } while(cur != -1);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
}
