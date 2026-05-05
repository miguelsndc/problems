#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n), freq(101);
    for (auto &x: a) cin >> x, freq[x]++;
    for (int i = 1; i <= 100; i++) {
        if (freq[i] > 1) {
            cout << -1 << '\n';
            return;
        }
    }
    sort(a.rbegin(), a.rend());
    if (n >= 2 and a[0] == a[1]) {
        cout << -1 << '\n';
    } else {
        for (int x: a) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}