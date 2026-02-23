#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, m, k; cin >> n >> m >> k;
    if (abs(n - m) > k or k > max(n,m)) {
        cout << -1 << '\n';
        return;
    }
    string ans;
    bool flip = false;
    if (m > n) {
        swap(n, m);
        flip = true;
    }
    for (int i = 0; i < k; i++) {
        ans += '0';
    }
    n -= k;
    int x = min(n, m);
    for (int i = 0; i < x; i++) {
        ans += "10";
    }
    n -= x;
    m -= x;
    for (int i = 0; i < m; i++) {
        ans += "1";
    }
    for (char c: ans) {
        int x = (int)(c - '0');
        if (flip) {
            cout << (x ^ 1);
        } else {
            cout << x;
        }
    }
    cout << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) dale();
}