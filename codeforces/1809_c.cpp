#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    int n, k;
    cin >> n >> k;
    function<vi(int, int)> f = [&](int n, int k) -> vi {
        vi a;
        if (n == 0) return a;
        if (k < n) {
            a.assign(n, -1);
            if (k > 0) a[k - 1] = 200;
            a[k] = -400;
        } else {
            a = f(n - 1, k - n);
            a.push_back(1000);
        }
        return a;
    };
    vi ans = f(n, k);
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) dale();
}