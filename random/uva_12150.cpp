#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while ((cin >> n) and n > 0) {
        vector<int> num(n + 1), delta(n + 1), ans(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            cin >> num[i] >> delta[i];
        }
        int sum = accumulate(delta.begin(), delta.end(), 0);
        if (sum != 0) {
            cout << -1 << '\n';
            continue;
        }
        bool ok = true;
        for (int i = n; i >= 1 and ok; i--) {
            if (ans[i + delta[i]] == -1)
                ans[i + delta[i]] = num[i];
            else ok = false;
        }
        if (ok) {
            for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
        } else {
            cout << -1 << '\n';
        }
    }
}
