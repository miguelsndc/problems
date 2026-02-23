#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void add(int pos, int val = 1) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    ll sum(int pos) const {
        if (pos < 0) return 0;
        ll s = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    while ((cin >> n >> m)) {
        vector<int> p(n), pos(n), queries(m), time(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i], --p[i];
            pos[p[i]] = i;
        }
        struct cara {
            int valor, pos, tempo;
        };
        Fenwick ft(n);
        vector<cara> a(n);
        for (int i = 0; i < m; i++) {
            cin >> queries[i];
            time[--queries[i]] = m - i;
        }
        for (int i = 0; i < n; i++) {
            a[i] = {p[i], pos[p[i]], time[p[i]]};
        }

        sort(a.begin(), a.end(), [&](cara& v1, cara& v2) {
            return v1.tempo < v2.tempo;
        });
        vector<ll> cnt(m + 1);
        function<void(int, int)> cdq = [&](int l, int r) {
            if (l == r) return;
            int m = (l + r) / 2;
            cdq(l, m);
            cdq(m + 1, r);
            int p = l;
            for (int f = m + 1; f <= r; f++) {
                while (p <= m and a[p].pos < a[f].pos) {
                    ft.add(a[p].valor, 1);
                    p++;
                }
                cnt[a[f].tempo] += ft.sum(n - 1) - ft.sum(a[f].valor);
            }
            for (int i = l; i < p; i++) ft.add(a[i].valor, -1);
            p = m;
            for (int f = r; f >= m + 1; f--) {
                while (p >= l and a[p].pos > a[f].pos) {
                    ft.add(a[p].valor, 1);
                    p--;
                }
                cnt[a[f].tempo] += ft.sum(a[f].valor);
            }
            for (int i = m; i > p; i--) ft.add(a[i].valor, -1);

            inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1, [&](const cara& v1, const cara& v2) {
                return v1.pos < v2.pos;
            });
        };

        cdq(0, n - 1);

        ll inv = accumulate(cnt.begin(), cnt.end(), 0ll);

        for (int i = m; i >= 1; i--) {
            cout << inv << '\n';
            inv -= cnt[i];
        }
    }
}