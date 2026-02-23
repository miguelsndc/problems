#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 2 << '\n';
        return;
    }
    if (n % 2 == 0) {
        cout << 1 << '\n';
        return;
    } else {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (i % 2 == 0 ? 1: -1) * a[i];
        }
        if (sum == 0) {
            cout << 2 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}