#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void dale() {
    int n; cin >> n;
    vector<int> a(n), lc(n, -1), rc(n, -1), par(n, -1);
    for (int &i: a) cin >> i;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!st.empty()) {
            int x = st.top();
            if (a[x] > a[i]) break;
            st.pop();
            last = x;
        }
        if (last != -1) {
            lc[i] = last;
            par[last] = i;
        }
        if (!st.empty()) { rc[st.top()] = i, par[i] = st.top(); }
        st.push(i);
    }

    function<pair<ll,ll>(int)> dfs = [&](int u) -> pair<ll,ll> {
        if (u == -1) return {0, 0};
        auto [lsize, leftsum] = dfs(lc[u]);
        auto [rsize, rightsum] = dfs(rc[u]);
        ll contrib = a[u] * (lsize + 1) * (rsize + 1);
        ll total = contrib + leftsum + rightsum;
        return {lsize + rsize + 1, total};
    };

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            root = i;
            break;
        }
    }

    auto [_, total] = dfs(root);

    cout << total << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}