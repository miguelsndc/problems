#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mxn = 1e3 + 5, mxm = 5e4 + 5;
int n, m; 
int p[mxn], v[mxn]; char cat[mxn];
void solve(int l, int r, vector<ll> dp) {
    if (l == r) {
        // aq tenho dp com todos os itens menos l
        // 0-> preciso dele 100%
        // 1-> talvez 
        // 2-> nao preciso
        ll sem = 0, mx = 0;
        for (int j = 0; j <= m; j++) {
            sem = max(sem, dp[j]);
            if (j <= m - p[l]) {
                mx = max(mx, dp[j]);
            }
        }
        ll com = v[l] + mx;
        ll vmax = max(sem, com);
        if (com == vmax and sem < vmax) {
            cat[l] = 'A';
        } else if (sem == vmax and com == vmax) {
            cat[l] = 'B';
        } else {
            cat[l] = 'C';
        }
        return;
    }
    int mid = (l + r) / 2;  
    vector<ll> left_dp = dp;
    for (int i = mid + 1; i <= r; i++) {
        for (int w = m; w >= p[i]; w--) {
            left_dp[w] = max(left_dp[w], left_dp[w - p[i]] + v[i]);
        }
    }
    solve(l, mid, left_dp);
    vector<ll> right_dp = dp;
    for (int i = l; i <= mid; i++) {
        for (int w = m; w >= p[i]; w--) {
            right_dp[w] = max(right_dp[w], right_dp[w - p[i]] + v[i]);
        }
    }
    solve(mid + 1, r, right_dp);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i] >> v[i];
    vector<ll> dp(m + 1);
    solve(0, n - 1, dp);
    for (int i = 0; i < n; i++) {
        cout << cat[i];
    }
}
