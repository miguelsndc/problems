#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return (x > 1);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        if (is_prime(a) and is_prime(b) and (a + 2) == b) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}