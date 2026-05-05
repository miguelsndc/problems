#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    string moves;
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        moves += c;
    }
    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int c: moves) {
            if (c == 'L') cur = L[cur];
            else cur = R[cur];
        }
        next[i] = cur;
    }

    const int LOG = 32;
    vector up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        up[0][i] = next[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    int cur = 1;
    for (int i = LOG -1 ; i >= 0; i--) {
        if (k >= (1ll << i)) {
            cur = up[i][cur];
            k -= (1 << i);
        }
    }

    cout << cur;
}