#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n,m,a,b;cin >>n>>m>>a>>b;
    if (__gcd(n,a) == 1 and __gcd(m, b) == 1 and __gcd(n, m) <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}
