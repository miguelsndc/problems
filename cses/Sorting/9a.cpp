#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int a, b; cin >> a >> b;
    int can = (6 - max(a, b) + 1);
    int denom = 6, num = can;
    int g = __gcd(denom, num);
    cout << num/g << "/" << denom/g << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}