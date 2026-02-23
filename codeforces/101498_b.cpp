#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) {
        string a, b; cin >> a >> b;
        vector<int> freqa(26), freqb(26);
        for (int i = 0; i < sz(b); i++) {
            freqb[(int)(b[i] - 'a')]++;
        }
        int ans = 0;
        for (int i = 0; i < sz(a); i++) {
            int c = (int)(a[i] - 'a');
            if (freqb[c] > 0) {
                freqb[c]--;
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
}