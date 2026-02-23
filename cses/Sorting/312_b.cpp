#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    cout.setf(ios::fixed);
    cout.precision(10);
    double a, b, c, d; cin >> a >> b >> c >> d;
    double x = a / b;
    double y = c / d;
    double p = x / (1 - ((1 - x) * (1 - y)));
    cout << p << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}