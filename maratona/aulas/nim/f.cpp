#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    /*
        gcd(x, move) = 1
        ai primo = moves = 1, ..., n - 1
        ai tem fator primo x entao todo y = 1...n com fator x ta removido
        
    */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}