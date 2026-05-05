#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (auto &x: a) cin >> x, sum += x;    
    if (sum & 1) {
        cout << "YES\n";
        return;
    }
    if (k * n % 2 == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}