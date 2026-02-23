#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
struct SparseTable {
    int n, k;
    vector<vector<int>> st;
    SparseTable(const vector<int> &v) {
        n = v.size(); k = 31 - __builtin_clz(n) + 1;
        st.resize(k); st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return min(st[p][l], st[p][r - (1 << p) + 1]);
    } 
};
void dale() {
    int n; cin >> n;
    vector<int> h(n);
    for (int &i: h) cin >> i;
    SparseTable rmq(h);
    int l = 1, r = n, ans = 1;
    while(l <= r) {
        int m = (l + r) / 2;
        bool ok = false;
        for (int i = 0; i + m - 1 < n; i++) {
            ok |= (rmq.query(i, i + m - 1) >= m);
        }
        if (ok) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}