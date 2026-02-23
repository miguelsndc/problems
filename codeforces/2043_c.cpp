    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    void dale() {
        int n; cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        auto mx = [&] (int l, int r) {
            int cur = a[l], mx = a[l];
            for (int i = l + 1; i < r; i++) {
                cur = max(a[i], cur + a[i]);
                mx = max(cur, mx);
            }
            return max(0, mx);
        };
        auto mn = [&] (int l, int r) {
            int cur = a[l], mn = a[l];
            for (int i = l + 1; i < r; i++) {
                cur = min(a[i], cur + a[i]);
                mn = min(cur, mn);
            }
            return min(0, mn);
        };
        int p = -1;
        for (int i=0;i<n;i++) if(a[i]!=1 and a[i]!=-1) p = i;
        if (p == -1) {
            int lo = mn(0, n);
            int hi = mx(0, n);
            cout << hi - lo + 1 << '\n';
            for (int x = lo; x <= hi; x++) cout << x << " \n"[x == hi];
            return;
        }
        int min_suf = 0, max_suf = 0, min_pre = 0, max_pre = 0, pre = 0, suf = 0;
        for (int i = p - 1; i >= 0; i--) {
            suf += a[i];
            min_suf = min(min_suf, suf);
            max_suf = max(max_suf, suf);
        }
        for (int i = p + 1; i < n; i++) {
            pre += a[i];
            min_pre = min(min_pre, pre);
            max_pre = max(max_pre, pre);
        }
    int L1 = 0, R1 = 0;

        if (p > 0) {
            L1 = mn(0, p);
            R1 = mx(0, p);
        }
        if (p + 1 < n) {
            L1 = min(L1, mn(p + 1, n));
            R1 = max(R1, mx(p + 1, n));
        }

        int L2 = min_suf + min_pre + a[p];
        int R2 = max_suf + max_pre + a[p];
        vector<int> l, r;
        l.assign(R2 - L2 + 1, 0);
        iota(l.begin(), l.end(), L2);
        r.assign(R1 - L1 + 1, 0);
        iota(r.begin(), r.end(), L1);
        if (L2 > R1) { 
            int sz = r.size() + l.size();
            cout << sz << '\n';
            for (int x: r) cout << x << ' ';
            for (int x: l) cout << x << ' ';
            cout << '\n';
        } else if (R2 < L1) {
            int sz = r.size() + l.size();
            cout << sz << '\n';
            for (int x: l) cout << x << ' ';
            for (int x: r) cout << x << ' ';
            cout << '\n';
        } else {
            int sz = max(R1, R2) - min(L1, L2) + 1;
            cout << sz << '\n';
            for (int x = min(L1, L2); x <=  max(R1, R2); x++) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    int main() {
        cin.tie(0)->sync_with_stdio(false);
        int tt = 1; cin >> tt;
        while (tt--) dale();
    }   