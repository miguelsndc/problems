#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define sz(x) (int)(x).size()
void slve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int pos_s = 0;

    for (; pos_s < sz(s); pos_s++) {
        if (s[pos_s] != s[0]) break;
    }
    for (int i = 0; i < q; i++) {
        string t; cin >> t;
        int ans = 0;
        if (s[0] != t[0]) {
            ans = max(ans, sz(s) + sz(t));
        }
        else {
            int pos_t = 0;
            for (; pos_t < sz(t); pos_t++) {
                if (t[pos_t] != t[0]) break;
            }   
            if (pos_s == sz(s) and pos_t == sz(t)) {
                ans = max(ans, max(sz(s), sz(t)));
            }
            else {
                ans = max(ans, sz(s) + sz(t) - min(pos_t, pos_s));
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}