#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, m, d; cin >> n >> m >> d;
    if (m > d) {
        cout << n << '\n';
        return;
    }    
    int am = d / m + 1; // qnts cabe numa torre
    cout << (n + am - 1) / am << '\n'; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}