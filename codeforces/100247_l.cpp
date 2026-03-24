#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
vector<int> get_divisors(int n) {
    vector<int> d;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) d.push_back(n / i);
        }
    }
    return d;
}
map<i64, i64> mp;
i64 f(i64 n) {
    if (mp.count(n)) return mp[n];
    i64 ans = n / 2 + 1;
    for (i64 d : get_divisors(n)) {
        i64 grupos = n / d;
        ans = min(ans, (grupos / 2 + 1) * f(d));
    }
    return mp[n] = ans;
}
void solve() {
    int n;
    cin >> n;
    cout << f(n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
