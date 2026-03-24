    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    using u64 = unsigned long long;
    using u32 = unsigned;

    using u128 = unsigned __int128;
    using i128 = __int128;

    void solve() {
        i64 n; cin >> n;
        for (i64 a = 0; a * a <= n; a++) {
            i64 b2 = n - (a * a);
            i64 b = sqrt(n - (a * a));
            if (b * b == b2) {
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int tt = 1; // cin >> tt;
        while(tt--) solve();
    }
