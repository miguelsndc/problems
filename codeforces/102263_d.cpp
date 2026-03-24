#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);
    int g = 0;
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x, g = __gcd(g, x);
    set<int> classes;
    for (auto x: a) classes.insert(x % g);
    if (classes.size() == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
