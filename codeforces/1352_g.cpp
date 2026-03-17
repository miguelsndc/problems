#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "-1\n";
        return;
    } else if (n == 4) {
        cout << "3 1 4 2\n";
        return;
    } else if (n == 5) {
        cout << "1 3 5 2 4\n";
        return;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    if (n & 1) {
        cout << n - 3 << ' ';
        cout << n - 1 << ' ';
        for (int i = n - 5; i > 0; i -= 2) {
            cout << i << ' ';
        }
    } else {
        cout << n - 4 << ' ';
        cout << n << ' ';
        cout << n - 2 << ' ';
        for (int i = n - 6; i > 0; i -= 2) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
