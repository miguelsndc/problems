#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int basis[32], sz = 0;
void insert(int x) {
    for (int b = 31; b >= 0; b--) if (x & (1 << b)) {
        if (basis[b] == -1) {
            basis[b] = x;
            sz++;
            return;
        }
        x ^= basis[b];
    }
}
void dale() {
    memset(basis, -1, sizeof basis);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(x);
    }
    cout << (1 << sz) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}