#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    int n; cin >> n;
    for (int i = n, j = 1; i >= j; i--, j++) {
        cout << i << ' ';
        if (i != j) {
            cout << j << ' ';
        }
    }
    cout << '\n';
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) dale();
}
