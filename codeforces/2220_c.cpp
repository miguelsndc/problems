#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int p, q; cin >> p >> q;
    int e = p + 2*q;
    for (int i = 1; i * i <= e; i++) {
        int num = (p + 2 * q - i) ;
        int den = (1 + 2 * i);
        if (num % den != 0) continue;
        int m = num / den;
        if (m > 0 and abs(m - i) <= p) {
            cout << i << ' ' << m << '\n';
            return;
        } 
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}