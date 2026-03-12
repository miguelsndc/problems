#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    i64 ans = 4e18;
    int m = (int)(a.size());
    for (int mask = 0; mask < (1 << 15); mask++) {
        bool should = false;
        vector<int> covered(m);
        i64 prod = 1;
        for (int i = 0; i < 15; i++) { // i sao primos
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < m; j++) { // j é array a
                if (covered[j]) continue;
                if (a[j] % primes[i] == 0) {
                    covered[j] = true;
                    should = true;
                } 
            }
            if (should) prod *= primes[i];
        }
        if (accumulate(covered.begin(), covered.end(), 0) == m) {
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
