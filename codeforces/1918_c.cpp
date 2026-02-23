#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    ll a, b, r; cin >> a >> b >> r;
    for (ll i = 0; i <= min(r, 100ll); i++) {
        cout << abs((a ^ i) - (b ^ i)) << ' ';
    }
    cout << "\n\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  cin >> tt;
    while(tt--) dale();
}