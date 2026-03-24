#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int mod = 100000007;

i64 fexp(i64 a, i64 b) {
    i64 ans = 1;
    for (; b > 0; b /= 2) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
    }
    return ans;
}

i64 solve() {
    int n; cin >> n;
    vector<i64> a(n);
    for (auto &x: a) cin >> x;
    i64 ans = 0;
    for (auto &x: a) {
        ans += x * fexp(2, n - 1) % mod;
        ans %= mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ": " << solve() << '\n';
    }
}
