#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<vector<int>> aut(n, vector<int>(26, n));
    vector<int> last(26, n);
    for (int i = n - 1; i >= 0; i--) {
        last[s[i] - 'a'] = i;
        for (int c = 0; c < 26; c++) {
            aut[i][c] = last[c];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, pos = i - 1;
        // nesse sufixo qual o maior prefixo que nao contem T como subsequencia
        while (l <= r) {  
            int mid = (l + r) / 2;
            
            int x = i;
            bool ok = false;

            for (int p = 0; p < m; p++) {
                if (x >= n) {
                    ok = true;
                    break;
                }
                x = aut[x][t[p] - 'a'];
                if (x > mid) {
                    ok = true;
                    break;
                }
                x++;
            }
            if (ok or sz(t) > (mid - i + 1)) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans += pos - i + 1;
    }
    cout << ans << '\n';
}