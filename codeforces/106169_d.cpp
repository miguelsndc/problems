#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    vector<int> perm(6), digs(6);
    for (int &i: digs) cin >> i;
    iota(perm.begin(), perm.end(), 0);
    vector<vector<int>> can(6, vector<int>(6, true));
    can[0][1] = can[1][0] = false;
    can[2][3] = can[3][2] = false;
    can[4][5] = can[5][4] = false;
    ll ans = 0;
    do {
        ll prod = digs[perm[0]] * pow(10, 5);
        bool ok = true;
        for (int i = 1; i < 6; i++) {
            if (can[perm[i - 1]][perm[i]]) {
                prod += digs[perm[i]] * pow(10, 6 - i - 1);
            } else {
                ok = false;
                break;
            }
        }
        if (ok) ans = max(ans, prod);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}