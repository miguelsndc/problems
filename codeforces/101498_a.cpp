#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int f; cin >> f;
            mp[f]++;
        }
        int mx = 0, ans = 0;
        for (auto [f, cnt]: mp) {
            if (cnt > mx) {
                mx = cnt;
                ans = f;
            }
        }
        cout << ans << '\n';
    }
}