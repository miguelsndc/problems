#include<bits/stdc++.h>
using namespace std;
const int sentinel = 1e9;
template<typename T> class SparseTable {
private:
    int n, k;
    vector<vector<T>> st;
public:
    SparseTable(const vector<T>& v) {
        n = (int)v.size(); k = 31 - __builtin_clz(n) + 1;
        st.resize(k); st[0] = v;
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
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    vector<int> perm(n), a(m), next(m, sentinel), last(n, sentinel), pos(n);
    for (int i = 0; i < n; i++) cin >> perm[i], --perm[i], pos[perm[i]] = i;
    for (int i = 0; i < m; i++) cin >> a[i], --a[i];
    for (int i = m - 1; i >= 0; i--) {
        next[i] = last[perm[(pos[a[i]] + 1) % n]];
        last[a[i]] = i;
    }
    const int LOG = 22;
    vector<vector<int>> jump(m, vector<int>(LOG, sentinel));
    for (int i = 0; i < m; i++) {
        jump[i][0] = next[i];
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i < m; i++) {
            int mid = jump[i][k - 1];
            if (mid != sentinel) {
                jump[i][k] = jump[mid][k - 1];
            }
        }
    }
    vector<int> v(m, sentinel);
    for (int i = 0; i < m; i++) {
        int p = i, found = false, rem = n - 1;
        for (int k = LOG - 1; k >= 0; k--) {
            if (rem >= (1 << k) and jump[p][k] != sentinel) {
                p = jump[p][k];
                found = true;
                rem -= (1 << k);
            }
        }
        if (found and rem <= 0) v[i] = p;
    }
    SparseTable<int> rmq(v);
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        if (rmq.query(l, r) <= r or n == 1) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
}