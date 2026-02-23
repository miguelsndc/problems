#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c; cin >> a >> b >> c;
        if (a < b and a < c) {
            cout << "First\n";
        } else if (b < a and b < c) {
            cout << "Second\n";
        } else {
            cout << "Third\n";
        }
    }
}