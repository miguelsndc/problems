#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 2e5 + 10;
int a[ms];
void dale() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;

    int first = a[0], last = a[n - 1];
    int ans = n;
    if (a[0] == a[n - 1]) {
        while (l < r) {
            if (a[l] == a[r] and a[l] == first) {
                l++, r--;
            } else {
                break;
            }
        };
        while(l < n and a[l] == first) l++;
        while(r >= 0 and a[r] == last) r--;
        ans = min(ans, max(r - l + 1, 0));
    } else {
        while(l < n and a[l] == first) l++;
        while(r >= 0 and a[r] == last) r--;
        ans = min(n - l,  r + 1);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}