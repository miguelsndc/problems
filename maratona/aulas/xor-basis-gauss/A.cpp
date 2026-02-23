#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void dale() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ny = 2 * a[0] - a[1];
    ll dy = n + 1;
    if(ny % dy != 0) {
        cout << "NO\n";
        return;
    }
    ll y = ny / dy;
    if(y < 0) {
        cout << "NO\n";
        return;
    }
    ll x = a[0] - n * y;
    if(x < 0) {
        cout << "NO\n";
        return;
    }
    for(ll i = 1; i <= n; i++) {
        ll cara = i * x + (n - i + 1) * y;
        if(cara != a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; 
    cin >> tt;
    while(tt--) dale();
}