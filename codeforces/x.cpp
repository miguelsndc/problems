#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

#define sz(x) (int)((x).size())

void solve() {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,43, 47};
    int n; cin >> n;
    vector<int> a(n);
    for (auto&x: a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = sz(primes); i64 ans = 4e18;
    for (int mask = 0; mask < (1 << m); mask++) {
        i64 prod = 1;
        vector<bool> covered(sz(a));
        for (int i = 0; i < m; i++) {
            bool found = false;
            for (int j = 0; j < sz(a); j++) {   
                if (!(mask & (1 << i))) continue;
                if (a[j] % primes[i] == 0) {
                    covered[j] = true;
                    found = true;
                }
            }
            if (found) prod *= primes[i];
        }
        if (!count(covered.begin(),covered.end(), false)) {
            ans = min(ans, prod);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
