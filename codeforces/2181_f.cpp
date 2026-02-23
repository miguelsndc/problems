#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    int cnt1 = 0, cntg = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) cnt1++;
        else cntg++;
    }
    if (cntg == 0) {
        cout << (cnt1 % 2 == 1 ? "Alice\n" : "Bob\n");
    } else {
        cout << ((cnt1 + 1) % 2 == 1 ? "Alice\n": "Bob\n");
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}