#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(11, -1);
    for (int i = 0; i < n; i++) {
        int b, d; cin >> b >> d;
        v[d] = max(v[d], b);
    }
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        if (v[i] == -1) {
            cout << "MOREPROBLEMS\n";
            return;
        }
        sum += v[i];
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
