#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    ll n; cin >> n;
    if (n % 2 == 0) {
        cout << 0 << '\n';
    } else {
        cout << (n + 1) / 2 << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}