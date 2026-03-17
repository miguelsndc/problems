#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    i64 sum = n * (n - 1) / 2;
    i64 k = (sum + 1) / 2;
    i64 l = 1, r = n - 1, ans = 1;
    auto f = [&] (i64 x) {
    return x * ((n - x) + (n - 1)) / 2;
    };
    while(l <= r) {
        i64 mid = l + (r - l) / 2;
        i64 tenho = f(mid);
        if (tenho >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans  << '\n';
}
