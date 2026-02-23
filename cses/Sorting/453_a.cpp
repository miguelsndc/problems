#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using f64 = long double;
void dale() {
    int n, m; cin >> n >> m;
    f64 lhs = n;
    auto exp = [&] (f64 base, int pow) {
        f64 res = 1;
        while(pow) {
            if (pow & 1) res = (res * base);
            base = (base * base);
            pow /= 2;
        }
        return res;
    };
    f64 rhs = 0;
    for (int i = 1; i <= n; i++) {
        rhs += exp((i - 1 + .0) / (n + .0), m);
    }
    cout.setf(ios::fixed);
    cout.precision(12);
    cout << lhs - rhs << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}