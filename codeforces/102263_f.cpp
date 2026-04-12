#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()

void solve() {
    int n, p; cin >> n >> p;
    vector<int> a(n), c(n), is_removed(n + 1), is_active(n + 1);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> c[i], is_removed[c[i]] = true;
    int w = 1;
    while(is_removed[w]) w++;
    vector<bool> dp(n + 1);
    dp[w] = true;
    is_active[w] = true;
    for (int i = n - 1; i >= 1; i--) {
        is_active[c[i]] = true;
        vector<int> S;
        for (int j = 1; j <= n; j++) {
            if (is_active[j]) S.push_back(j);
        }
        vector<bool> nxt(n + 1);
        int k = sz(S);
        for (int j = 0; j < k; j++) {
            if (dp[S[j]]) { // vencedor
                ll step = a[i] % k;
                ll start_cw = (j - step + k) % k;
                ll start_ccw = (j + step) % k;
                nxt[S[start_ccw]] = true;
                nxt[S[start_cw]] = true;
            }
        }
        dp = nxt;
    }
    if (dp[p]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
