#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {  
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int bla = a[i], ble = i;
        while (bla % 2 == 0) bla /= 2;
        while (ble % 2 == 0) ble /= 2;
        if (bla != ble) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}