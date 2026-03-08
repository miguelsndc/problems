#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int ans = 0;
    while(sz(s) >0 or sz(t)> 0) {
        if (sz(s) > 0 and sz(t) > 0 and s.back() == t.back()) {
            s.pop_back();
            t.pop_back();
        } else if (sz(t) > 0 and t.back() == 'A' and (s.empty() or (s.size() > 0 and s.back() != 'A'))) {
            t.pop_back();
            ans++;
        } else if (sz(t) > 0 and t.back() != 'A' and (s.empty() or (s.size() > 0 and s.back() != 'A' ))) {
            cout << -1;
            exit(0);
        } else if (sz(s) > 0 and s.back() == 'A' and (t.empty() or (sz(t) > 0 and t.back() != 'A'))) {
            s.pop_back();
            ans++;
        } else {
            cout << -1;
            exit(0);
        }
    }
    cout << ans;
}   
