#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    string s; cin >> s;
    int n = s.size();
    vector<int> bal(n + 1), p(n);
    iota(all(p), 0);
    int b = 0;
    for (int i = 0; i < n; i++) {
        b += (s[i] == '(' ? 1: -1);
        bal[i + 1] = b;
    }
    sort(all(p), [&](const auto &v1, const auto &v2) {
        if (bal[v1] == bal[v2]) {
            return v1 > v2;
        }
        return bal[v1] < bal[v2];
    });
    for (int i = 0; i < n; i++) {
        cout << s[p[i]];
    }
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int tt; cin >> tt;
    // while(tt--) dale();
    dale();
}
