#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define _sz(x) (int((x).size()))
template <typename T>
class SparseTable {
private:
    int n, k;
    vector<vector<T>> st;

public:
    SparseTable(const vector<T>& v) {
        n = v.size();
        k = 31 - __builtin_clz(n) + 1;
        st.resize(k);
        st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return min(st[p][l], st[p][r - (1 << p) + 1]);
    }
};
void arrocha() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    SparseTable<ll> t(a);
    vector dp(n, vector<ll>(n, -1));
    auto solve = [&](auto& solve, int l, int r, ll offset) -> ll {
        if (l == r) return 1;
        if (~dp[l][r]) return dp[l][r];
        ll cost = r - l + 1;
        ll rm = t.query(l, r) - offset, mc = rm;
        int j = l;
        for (int i = l; i <= r; i++) {
            j = i;
            while (j + 1 < n and t.query(i, j + 1) > rm + offset) j++;
            if (t.query(i, j) > offset + rm) {
                mc += solve(solve, i, j, offset + rm);
            }
            i = j;
        }
        return dp[l][r] = min(cost, mc);
    };
    cout << solve(solve, 0, n - 1, 0);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) arrocha();
}