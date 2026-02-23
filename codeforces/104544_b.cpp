#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    int ga = 0, gb = 0;
    rg::for_each(a, [&](int v) { ga = __gcd(ga, v); });
    rg::for_each(b, [&](int v) { gb = __gcd(gb, v); });

    if (ga == gb) {
        cout << 0 << '\n';
    } else if ((gb % ga == 0) or (ga % gb == 0)) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}