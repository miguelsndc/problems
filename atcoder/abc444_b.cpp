#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    auto sum = [&] (int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) if (sum(i) == k) ans++;
    cout << ans << '\n';
}