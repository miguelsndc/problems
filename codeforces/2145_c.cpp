#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> pre(n + 1);
        int ca = count(s.begin(),s.end(), 'a');
        int cb = count(s.begin(),s.end(), 'b');
        if (ca < cb) {
            swap(ca, cb);
            for (char &c: s) {
                if (c == 'b') {
                    c = 'a'; 
                } else {
                    c = 'b';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (s[i] == 'a' ? 1: -1);
        }
        int d = ca - cb;
        if (d == 0) {
            cout << 0 << '\n';
            continue;
        }
        map<int,int> mp;
        int ans = n;
        mp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (mp.count(pre[i] - d)) {
                ans = min(ans, i - mp[pre[i] - d]);
            }
            mp[pre[i]] = i;
        }
        cout << (ans == n ? -1 : ans) << '\n';
    }
}