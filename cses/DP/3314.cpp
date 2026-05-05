#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
void slve() {
    int n; cin >> n;
    /*
        cada cara vai tem um range [x - l, x + l] q ele pode ir
        achar maior caminho nesse dag
    */
    vector<int> h(n);
    for (auto& x : h) cin >> x;
    int mx = *max_element(h.begin(), h.end());
    vector<int> left(n, -1), right(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() > 0 and h[st.top()] <= h[i]) st.pop();
        if (st.size() > 0) right[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        while (st.size() > 0 and h[st.top()] <= h[i]) st.pop();
        if (st.size() > 0) left[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    vector<int> dp(n, -1);
    auto f = [&] (auto &&self, int i) -> int {
        if (i < 0 or i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int le = self(self, left[i]);
        int ri = self(self, right[i]);
        return dp[i] = 1 + max(le, ri);
    };
    for (int i = 0; i < n; i++) {
        ans = max(ans, f(f, i));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}