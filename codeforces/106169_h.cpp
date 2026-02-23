#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 1e9 + 7;
void dale() {
    int n;
    cin >> n;
    stack<pair<int, ll>> st;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "for") {
            int x;
            cin >> x;
            st.push({0, x});
        }
        if (op == "calc") {
            int x;
            cin >> x;
            st.push({1, x});
        }
        if (op == "end") {
            ll acum = 0;
            while (st.size() and st.top().first == 1) {
                acum += st.top().second;
                acum %= mod;
                st.pop();
            }
            ll res = ((st.top().second) * acum) % mod;
            st.pop();
            st.push({1, res});
        }
    }
    while (st.size()) ans = (ans + st.top().second) % mod, st.pop();
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}