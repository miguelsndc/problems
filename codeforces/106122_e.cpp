#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Range (Idempotent Function) Query
    Build - O(n log n)
    Query - O(1)
    No updates
*/

template<typename T> class SparseTable {
private:
    int n, k;
    vector<vector<T>> st;
public: 
    SparseTable(const vector<T> & v) {
        n = v.size();
        k = 31 - __builtin_clz(n) + 1;
        st.resize(k);
        st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = max(st[i - 1][j],
                               st[i - 1][j + (1 << (i - 1))]);
        }
    }
    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return max(st[p][l], st[p][r - (1 << p) + 1]);
    }
};

void dale() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    int m = n - k + 1;
    vector<ll> w(m), pre(m), suf(m);

    ll sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];

    int i = 0, j = k - 1;
    while (j < n) {
        w[i] = sum;
        if (++j < n) sum += a[j];
        sum -= a[i++];
    }

    pre[0] = w[0];
    for (int i = 1; i < m; i++)
        pre[i] = max(pre[i - 1], w[i]);

    suf[m - 1] = w[m - 1];
    for (int i = m - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], w[i]);

    SparseTable<ll> st(w);

    ll ans = LLONG_MAX;

    for (int idx = 0; idx < n; idx++) {
        int L = max(0, idx - k + 1);
        int R = min(idx, m - 1);

        ll fora = 0;
        if (L > 0) fora = max(fora, pre[L - 1]);
        if (R + 1 < m) fora = max(fora, suf[R + 1]);

        ll dentro = st.query(L, R) - a[idx];

        ll worst = max(fora, dentro);
        ans = min(ans, worst);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    while (tt--) dale();
}
