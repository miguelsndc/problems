#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    int carry = 0, cost = 0;
    for (int i = n - 1; i >= 0; i--) {
        int d = a[i] + carry;
        if (d == 10) {
            carry = 1;
            continue;
        }
        if (d < 5) {
            cost += d;
            carry = 0;
        } else if (d > 5) {
            cost += 10 - d;
            carry = 1;
        } else {  // d == 5
            cost += 5;
            carry = (i > 0 and a[i - 1] >= 5);
        }
    }
    cost += carry;
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
