#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, k; cin >> n >> k;
    int msb = 31 - __builtin_clz(n);
    vector<int> ans(k);
    vector<int> tight, loose;
    int qt = (k % 2 == 1) ? k  : k - 1;
    for (int j = 0; j < k; j++) {
        if (j < qt) {
            ans[j] |= (1 << msb);
            tight.emplace_back(j);
        }
        else {
            loose.emplace_back(j);
        }
    }
    for (int b = msb - 1; b >= 0; b--) {
        if (n & (1 << b)) {
            int m = (int)(loose.size());
            int p = (int)tight.size();
            for (int idx = 0; idx < min(m, qt); idx++) {
                ans[loose[idx]] |= (1 << b);
            }
            for (int idx = 0; idx < qt - min(m, qt); idx++) {
                ans[tight[idx]] |= (1 << b);
            }
            for (int i = qt - min(m, qt); i < p; i++)loose.push_back(tight[i]);
            tight.resize(qt - min(m, qt));
        }
        else {
            // par
            int m = (int)(loose.size());
            for (int idx = 0; idx < (m - (m % 2)); idx++) {
                ans[loose[idx]] |= (1 << b);
            }
        }
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}