    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    using u64 = unsigned long long;
    using u32 = unsigned;

    using u128 = unsigned __int128;
    using i128 = __int128;

    void solve() {
        int n, p, q;
        cin >> n >> p >> q;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        if (p == q) {
            cout << (*max_element(a.begin(), a.end()) + p - 1) / p << '\n';
            return;
        }
        i64 l = 1, r = 1e9, tot = 1e9;
        while (l <= r) {
            i64 mid = l + (r - l) / 2;
            i64 extra = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mid * q) {
                    extra += (a[i] - mid * q + p - q - 1) / (p - q);
                }
            }
            if (extra <= mid) {
                tot = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << tot << '\n';
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int tt = 1;  // cin >> tt;
        while (tt--) solve();
    }