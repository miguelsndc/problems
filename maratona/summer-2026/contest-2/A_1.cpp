#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    a.push_back(0);
    stack<int> st;
    auto get = [&] () {
        return st.size() > 0 ? st.top(): -1;
    };
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while (st.size() > 0 and a[st.top()] >= a[i]) {
            int altura = a[st.top()];
            st.pop();
            ans = max(ans, min(i - get() - 1, altura));
        }
        st.push(i);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}