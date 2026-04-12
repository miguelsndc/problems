#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("looking.in", "r", stdin);
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (auto &x: a) cin >> x;
        vector<int> bits(21);
        for (int b = 0; b < 21; b++) {
            for (int x: a) {
                   if (x & (1 << b)) {
                    bits[b] = 1;
                }
            }
        }
        long long ans = 0;
        for (int b = 20; b >= 0; b--) {
            if (bits[b]) {
                ans |= (1 << b);
            }   
        }
        cout << ans << '\n';
    }
}
